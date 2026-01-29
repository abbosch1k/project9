#include <bits/stdc++.h>
using namespace std;
int main(){
    string c="abc123XYZ!@";
    srand(time(0));
    for(int i=0;i<8;i++) cout<<c[rand()%c.size()];
}
