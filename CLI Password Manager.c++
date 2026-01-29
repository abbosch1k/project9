#include <iostream>
#include <unordered_map>
#include <functional>

int main() {
    std::unordered_map<std::string, size_t> storage;
    std::hash<std::string> hasher;

    std::string cmd, user, pass;

    while (true) {
        std::cin >> cmd;
        if (cmd == "add") {
            std::cin >> user >> pass;
            storage[user] = hasher(pass);
        } else if (cmd == "check") {
            std::cin >> user >> pass;
            std::cout << (storage[user] == hasher(pass)) << "\n";
        } else break;
    }
}
