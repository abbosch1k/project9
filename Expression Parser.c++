#include <iostream>
#include <sstream>

int main() {
    std::string expr;
    std::getline(std::cin, expr);
    std::istringstream ss(expr);
    int a,b; char op;
    ss >> a >> op >> b;
    if(op=='+') std::cout << (a+b);
    else if(op=='-') std::cout << (a-b);
    else if(op=='*') std::cout << (a*b);
    else if(op=='/') std::cout << (a/b);
}
