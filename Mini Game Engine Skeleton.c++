#include <iostream>

class GameObject {
public:
    virtual void update(){ std::cout << "Updating object\n"; }
};

int main() {
    GameObject obj;
    for(int i=0;i<3;i++) obj.update();
}
