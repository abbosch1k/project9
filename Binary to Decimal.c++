#include <iostream>
using namespace std;
int main(){
    string b; cin>>b;
    int d=0;
    for(char c:b) d=d*2+(c-'0');
    cout<<d;
}
