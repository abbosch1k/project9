#include <fstream>
using namespace std;
int main(){
    ifstream a("a.txt"); ofstream b("b.txt");
    b<<a.rdbuf();
}
