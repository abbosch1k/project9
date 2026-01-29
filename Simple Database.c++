#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string,std::string> db;
    db["name"] = "Akram";
    db["lang"] = "C++";
    std::cout << db["name"] << " uses " << db["lang"] << "\n";
}
