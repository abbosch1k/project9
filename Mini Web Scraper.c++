#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream f("page.html");
    std::string line;
    while(std::getline(f,line)) if(line.find("<title>")!=std::string::npos) std::cout<<line<<"\n";
}
