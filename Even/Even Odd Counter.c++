#include <iostream>
using namespace std;
int main(){
    int x,e=0,o=0;
    while(cin>>x) x%2?o++:e++;
    cout<<e<<" "<<o;
}
