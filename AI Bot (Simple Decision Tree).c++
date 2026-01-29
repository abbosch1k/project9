#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Ask a question: ";
    std::getline(std::cin, input);
    if(input=="hello") std::cout << "Hi!\n";
    else if(input=="bye") std::cout << "Goodbye!\n";
    else std::cout << "I don't know\n";
}
