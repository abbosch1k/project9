#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("file.txt");
    std::string line;
    while(std::getline(file,line)) std::cout << line << "\n";
}
