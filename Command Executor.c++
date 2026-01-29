#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    std::string cmd;
    std::cout << "Enter command: ";
    std::getline(std::cin, cmd);
    system(cmd.c_str());
}
