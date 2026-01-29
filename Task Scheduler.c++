#include <iostream>
#include <thread>
#include <chrono>

void task(const std::string& name, int sec) {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
    std::cout << name << " executed\n";
}

int main() {
    std::thread t1(task, "TaskA", 2);
    std::thread t2(task, "TaskB", 1);

    t1.join();
    t2.join();
}
