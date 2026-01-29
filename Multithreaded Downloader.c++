#include <iostream>
#include <thread>
#include <vector>

void downloadPart(int id) {
    std::cout << "Downloading part " << id << "\n";
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.emplace_back(downloadPart, i);
    }
    for (auto& t : threads) t.join();
    std::cout << "Download completed\n";
}
