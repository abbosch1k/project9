#include <iostream>
using namespace std;
int main(){
    double a,b; char o;
    cin>>a>>o>>b;
    if(o=='+') cout<<a+b;
    if(o=='-') cout<<a-b;
    if(o=='*') cout<<a*b;
    if(o=='/') cout<<a/b;
}
