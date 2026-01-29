#include <stack>
#include <mutex>
#include <thread>
#include <iostream>

std::stack<int> s;
std::mutex mtx;

void pushValues(){ for(int i=0;i<5;i++){ std::lock_guard<std::mutex> l(mtx); s.push(i); } }
void popValues(){ while(true){ std::lock_guard<std::mutex> l(mtx); if(!s.empty()){ std::cout<<s.top()<<"\n"; s.pop(); } else break; } }

int main() {
    std::thread t1(pushValues), t2(popValues);
    t1.join(); t2.join();
}
