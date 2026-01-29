#include <iostream>
#include <functional>
#include <vector>

class Event {
    std::vector<std::function<void()>> listeners;
public:
    void subscribe(std::function<void()> f) { listeners.push_back(f); }
    void fire() { for(auto& l : listeners) l(); }
};

int main() {
    Event e;
    e.subscribe([]{ std::cout << "Listener 1\n"; });
    e.subscribe([]{ std::cout << "Listener 2\n"; });
    e.fire();
}
