#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    bool p=n>1;
    for(int i=2;i*i<=n;i++) if(n%i==0) p=false;
    cout<<(p?"Prime":"Not prime");
}
