#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream mem("/proc/meminfo");
    std::ifstream cpu("/proc/stat");
    std::string line;
    std::cout << "--- MEMORY ---\n";
    while(std::getline(mem,line)) std::cout<<line<<"\n";
    std::cout << "--- CPU ---\n";
    while(std::getline(cpu,line)) std::cout<<line<<"\n";
}
