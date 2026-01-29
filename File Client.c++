#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("file.txt");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::cout << content;
}
