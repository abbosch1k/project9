#include <iostream>

class Rigidbody {
public:
    float pos=0, vel=0, acc=1;
    void update(){ vel+=acc; pos+=vel; }
};

int main() {
    Rigidbody obj;
    for(int i=0;i<5;i++){
        obj.update();
        std::cout << "Pos: " << obj.pos << "\n";
    }
}
