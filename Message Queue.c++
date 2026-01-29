#include <queue>
#include <mutex>
#include <thread>
#include <iostream>

std::queue<int> q;
std::mutex mtx;

void producer() { for(int i=0;i<5;i++){ std::lock_guard<std::mutex> l(mtx); q.push(i); } }
void consumer() { while(true){ std::lock_guard<std::mutex> l(mtx); if(!q.empty()){ std::cout<<q.front()<<"\n"; q.pop(); } else break; } }

int main() {
    std::thread t1(producer), t2(consumer);
    t1.join(); t2.join();
}
