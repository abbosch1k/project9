#include <iostream>
#include <vector>

class Neuron {
public:
    std::vector<float> weights;
    float bias=0;
    float output=0;
};

int main() {
    Neuron n;
    n.weights = {0.5,0.3};
    n.bias=0.1;
    n.output = n.weights[0]*1 + n.weights[1]*2 + n.bias;
    std::cout << "Output: " << n.output << "\n";
}
