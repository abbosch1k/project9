#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream f("/proc/self/status");
    std::string line;
    while(std::getline(f,line)) std::cout << line << "\n";
}
