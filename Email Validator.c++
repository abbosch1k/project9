#include <iostream>
using namespace std;
int main(){
    string e; cin>>e;
    cout<<(e.find('@')!=string::npos?"Valid":"Invalid");
}
