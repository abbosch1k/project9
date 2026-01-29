#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    set<int> s;
    while(s.size()<6) s.insert(rand()%49+1);
    for(int x:s) cout<<x<<" ";
}
