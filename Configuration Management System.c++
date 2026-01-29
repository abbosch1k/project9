#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() {
    std::ifstream f("config.ini");
    std::unordered_map<std::string,std::string> cfg;
    std::string line;
    while(std::getline(f,line)){
        auto pos = line.find('=');
        if(pos!=std::string::npos)
            cfg[line.substr(0,pos)] = line.substr(pos+1);
    }
    for(auto &p:cfg) std::cout << p.first << "=" << p.second << "\n";
}
