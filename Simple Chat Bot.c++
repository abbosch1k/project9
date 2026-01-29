#include <iostream>
#include <string>

int main() {
    std::string msg;
    while(true){
        std::cout << "You: ";
        std::getline(std::cin, msg);
        if(msg=="exit") break;
        std::cout << "Bot: I received '" << msg << "'\n";
    }
}
