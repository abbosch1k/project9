#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("code.cpp");
    std::string line;
    int braces = 0;
    while(std::getline(file,line)) {
        for(char c:line) {
            if(c=='{') braces++;
            else if(c=='}') braces--;
        }
    }
    if(braces==0) std::cout << "Braces OK\n";
    else std::cout << "Braces mismatch\n";
}
