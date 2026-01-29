#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>

class Logger {
    std::mutex mtx;
    std::ofstream file;

public:
    Logger(const std::string& name) {
        file.open(name, std::ios::app);
    }

    void log(const std::string& msg) {
        std::lock_guard<std::mutex> lock(mtx);
        file << msg << std::endl;
    }
};

int main() {
    Logger logger("log.txt");

    auto worker = [&](int id) {
        logger.log("Thread " + std::to_string(id) + " logging");
    };

    std::thread t1(worker, 1);
    std::thread t2(worker, 2);

    t1.join();
    t2.join();
}
