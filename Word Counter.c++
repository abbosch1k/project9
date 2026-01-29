#include <iostream>
using namespace std;
int main(){
    string s; getline(cin,s);
    int c=1;
    for(char x:s) if(x==' ') c++;
    cout<<c;
}
