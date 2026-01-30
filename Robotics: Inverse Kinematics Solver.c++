#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class DHParameters {
public:
    double a, alpha, d, theta;
    
    DHParameters(double a, double alpha, double d, double theta)
        : a(a), alpha(alpha), d(d), theta(theta) {}
    
    std::vector<std::vector<double>> getTransformMatrix() {
        double ct = cos(theta);
        double st = sin(theta);
        double ca = cos(alpha);
        double sa = sin(alpha);
        
        return {
            {ct, -st*ca, st*sa, a*ct},
            {st, ct*ca, -ct*sa, a*st},
            {0, sa, ca, d},
            {0, 0, 0, 1}
        };
    }
};

class RobotArm {
private:
    std::vector<DHParameters> dhParams;
    std::vector<double> jointLimitsMin, jointLimitsMax;
    
public:
    RobotArm() {
        // Example: 6-DOF industrial robot
        dhParams.push_back(DHParameters(0, M_PI/2, 0.3, 0));
        dhParams.push_back(DHParameters(0.5, 0, 0, 0));
        dhParams.push_back(DHParameters(0.1, M_PI/2, 0, 0));
        dhParams.push_back(DHParameters(0, -M_PI/2, 0.4, 0));
        dhParams.push_back(DHParameters(0, M_PI/2, 0, 0));
        dhParams.push_back(DHParameters(0, 0, 0.1, 0));
        
        jointLimitsMin = {-M_PI, -M_PI/2, -M_PI/2, -M_PI, -M_PI/2, -M_PI};
        jointLimitsMax = {M_PI, M_PI/2, M_PI/2, M_PI, M_PI/2, M_PI};
    }
    
    std::vector<std::vector<double>> forwardKinematics(const std::vector<double>& jointAngles) {
        std::vector<std::vector<double>> T = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };
        
        for(size_t i = 0; i < dhParams.size(); i++) {
            auto dh = dhParams[i];
            dh.theta = jointAngles[i];
            auto Ti = dh.getTransformMatrix();
            T = multiplyMatrices(T, Ti);
        }
        
        return T;
    }
    
    std::vector<double> inverseKinematics(const std::vector<double>& targetPos, 
                                         const std::vector<double>& targetOrientation) {
        // Simplified Jacobian-based IK
        std::vector<double> currentAngles(dhParams.size(), 0);
        std::vector<double> error(6, 0);
        double lambda = 0.1;
        
        for(int iteration = 0; iteration < 100; iteration++) {
            auto T = forwardKinematics(currentAngles);
            
            // Position error
            error[0] = targetPos[0] - T[0][3];
            error[1] = targetPos[1] - T[1][3];
            error[2] = targetPos[2] - T[2][3];
            
            // Simple gradient descent update
            for(size_t i = 0; i < currentAngles.size(); i++) {
                currentAngles[i] += lambda * (error[0] + error[1] + error[2]);
                
                // Apply joint limits
                if(currentAngles[i] < jointLimitsMin[i]) 
                    currentAngles[i] = jointLimitsMin[i];
                if(currentAngles[i] > jointLimitsMax[i]) 
                    currentAngles[i] = jointLimitsMax[i];
            }
            
            double totalError = sqrt(error[0]*error[0] + error[1]*error[1] + error[2]*error[2]);
            if(totalError < 0.001) break;
        }
        
        return currentAngles;
    }
    
private:
    std::vector<std::vector<double>> multiplyMatrices(
        const std::vector<std::vector<double>>& A,
        const std::vector<std::vector<double>>& B) {
        
        std::vector<std::vector<double>> C(4, std::vector<double>(4, 0));
        
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return C;
    }
};

int main() {
    RobotArm arm;
    std::vector<double> targetPos = {0.6, 0.2, 0.8};
    std::vector<double> targetOrientation = {0, 0, 0};
    
    auto jointAngles = arm.inverseKinematics(targetPos, targetOrientation);
    
    std::cout << "Inverse Kinematics Solution:\n";
    for(size_t i = 0; i < jointAngles.size(); i++) {
        std::cout << "Joint " << i+1 << ": " 
                  << std::setprecision(4) << jointAngles[i] * 180/M_PI << " deg\n";
    }
    
    return 0;
}
