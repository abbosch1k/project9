#include <iostream>
#include <fstream>
#include <mutex>

class Logger {
    std::ofstream file;
    std::mutex mtx;
public:
    Logger(const std::string& name){ file.open(name, std::ios::app); }
    void log(const std::string& msg){
        std::lock_guard<std::mutex> l(mtx);
        file << msg << std::endl;
    }
};

int main() {
    Logger log("app.log");
    log.log("Started");
    log.log("Processing");
}
