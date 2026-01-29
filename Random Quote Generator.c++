#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> q={"Stay strong","Keep coding","Never quit"};
    srand(time(0));
    cout<<q[rand()%q.size()];
}
