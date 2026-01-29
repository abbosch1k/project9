#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string cmd;
    while(true){
        std::cout << "shell> ";
        std::getline(std::cin, cmd);
        if(cmd=="exit") break;
        system(cmd.c_str());
    }
}
