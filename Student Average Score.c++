#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    double s=0,x;
    for(int i=0;i<n;i++){cin>>x; s+=x;}
    cout<<s/n;
}
