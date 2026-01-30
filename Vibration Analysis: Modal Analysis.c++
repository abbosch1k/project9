#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>

class ModalAnalyzer {
private:
    std::vector<std::vector<double>> massMatrix;
    std::vector<std::vector<double>> stiffnessMatrix;
    std::vector<std::vector<double>> dampingMatrix;
    
public:
    ModalAnalyzer(int degreesOfFreedom) {
        massMatrix.resize(degreesOfFreedom, std::vector<double>(degreesOfFreedom, 0));
        stiffnessMatrix.resize(degreesOfFreedom, std::vector<double>(degreesOfFreedom, 0));
        dampingMatrix.resize(degreesOfFreedom, std::vector<double>(degreesOfFreedom, 0));
        
        // Initialize with example values (diagonal matrices for simplicity)
        for(int i = 0; i < degreesOfFreedom; i++) {
            massMatrix[i][i] = 1.0; // 1 kg each mass
            stiffnessMatrix[i][i] = 1000.0; // 1000 N/m stiffness
            if(i > 0) {
                stiffnessMatrix[i][i-1] = -500.0;
                stiffnessMatrix[i-1][i] = -500.0;
            }
            dampingMatrix[i][i] = 5.0; // 5 Ns/m damping
        }
    }
    
    std::vector<std::complex<double>> solveEigenproblem() {
        int n = massMatrix.size();
        std::vector<std::complex<double>> eigenvalues;
        
        // Simplified eigenvalue solver for 2-DOF system
        if(n == 2) {
            double m1 = massMatrix[0][0];
            double m2 = massMatrix[1][1];
            double k1 = stiffnessMatrix[0][0] + stiffnessMatrix[0][1];
            double k2 = stiffnessMatrix[1][1] + stiffnessMatrix[1][0];
            double k12 = -stiffnessMatrix[0][1];
            
            // Solve quadratic equation for eigenvalues
            double a = m1 * m2;
            double b = -(m1*k2 + m2*k1);
            double c = k1*k2 - k12*k12;
            
            double discriminant = b*b - 4*a*c;
            
            if(discriminant >= 0) {
                eigenvalues.push_back(std::complex<double>((-b + sqrt(discriminant))/(2*a), 0));
                eigenvalues.push_back(std::complex<double>((-b - sqrt(discriminest)/(2*a), 0));
            } else {
                eigenvalues.push_back(std::complex<double>(-b/(2*a), sqrt(-discriminant)/(2*a)));
                eigenvalues.push_back(std::complex<double>(-b/(2*a), -sqrt(-discriminant)/(2*a)));
            }
        }
        
        return eigenvalues;
    }
    
    std::vector<double> calculateNaturalFrequencies() {
        auto eigenvalues = solveEigenproblem();
        std::vector<double> naturalFreqs;
        
        for(const auto& lambda : eigenvalues) {
            double omega_n = sqrt(std::abs(lambda));
            naturalFreqs.push_back(omega_n / (2*M_PI)); // Convert to Hz
        }
        
        std::sort(naturalFreqs.begin(), naturalFreqs.end());
        return naturalFreqs;
    }
    
    std::vector<double> calculateForcedResponse(double frequency, 
                                               const std::vector<double>& force) {
        int n = massMatrix.size();
        std::vector<double> response(n, 0);
        double omega = 2 * M_PI * frequency;
        
        // Solve: (-ω²M + iωC + K)X = F
        std::vector<std::vector<std::complex<double>>> dynamicStiffness(
            n, std::vector<std::complex<double>>(n, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                std::complex<double> value(
                    stiffnessMatrix[i][j] - omega*omega*massMatrix[i][j],
                    omega*dampingMatrix[i][j]
                );
                dynamicStiffness[i][j] = value;
            }
        }
        
        // Simple solution for demonstration (in practice, use linear solver)
        for(int i = 0; i < n; i++) {
            response[i] = force[i] / std::abs(dynamicStiffness[i][i]);
        }
        
        return response;
    }
};

int main() {
    ModalAnalyzer analyzer(2);
    
    auto naturalFreqs = analyzer.calculateNaturalFrequencies();
    std::cout << "Modal Analysis Results:\n";
    std::cout << "Natural Frequencies:\n";
    for(size_t i = 0; i < naturalFreqs.size(); i++) {
        std::cout << "Mode " << i+1 << ": " << naturalFreqs[i] << " Hz\n";
    }
    
    std::vector<double> force = {10.0, 0}; // 10N force on first mass
    auto response = analyzer.calculateForcedResponse(5.0, force);
    
    std::cout << "\nForced Response at 5 Hz:\n";
    for(size_t i = 0; i < response.size(); i++) {
        std::cout << "Mass " << i+1 << " amplitude: " << response[i] << " m\n";
    }
    
    return 0;
}
