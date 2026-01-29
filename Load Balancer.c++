#include <iostream>
#include <vector>
int main() {
    std::vector<std::string> servers = {"Server1", "Server2", "Server3"};
    for (int i = 0; i < 10; i++) {
        std::cout << "Request " << i << " sent to " << servers[i % servers.size()] << "\n";
    }
}
