#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    int g,n=rand()%10;
    while(cin>>g && g!=n) cout<<"Try again\n";
    cout<<"Win!";
}
