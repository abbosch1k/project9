#include <iostream>
using namespace std;
int main(){
    string s,r; cin>>s;
    r=s; reverse(r.begin(),r.end());
    cout<<(s==r);
}
