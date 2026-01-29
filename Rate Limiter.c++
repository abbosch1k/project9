#include <iostream>
#include <thread>
#include <chrono>

int main() {
    int tokens = 5;
    for (int i = 1; i <= 10; i++) {
        if (tokens > 0) {
            std::cout << "Request " << i << " allowed\n";
            tokens--;
        } else {
            std::cout << "Request " << i << " limited\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if (i % 2 == 0) tokens++;
    }
}
