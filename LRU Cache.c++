#include <iostream>
#include <list>
#include <unordered_map>

class LRU {
    std::list<int> dq;
    std::unordered_map<int,int> map;
    int cap;
public:
    LRU(int c): cap(c) {}
    void access(int x) {
        if(map.count(x)) dq.remove(x);
        else if(dq.size()>=cap){ map.erase(dq.back()); dq.pop_back(); }
        dq.push_front(x); map[x]=1;
    }
    void print(){ for(int v:dq) std::cout<<v<<" "; std::cout<<"\n"; }
};

int main() {
    LRU l(3);
    l.access(1); l.access(2); l.access(3); l.print();
    l.access(2); l.access(4); l.print();
}
