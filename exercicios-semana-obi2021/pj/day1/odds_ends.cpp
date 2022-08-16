// https://codeforces.com/problemset/problem/849/A
// stdc++
#include "bits/stdc++.h"
using namespace std;

int main(){
    int n; cin >> n;
    int v[n+1];
    for (int i=0; i < n; i++) cin >> v[i];
    bool opened = false;
    bool impossible = false;
    int formed=0;
    int length=1;
    v[n] = 1;
    for (int i = 0; i < n; i++)
    {
        if (opened and v[i]%2==1 and v[i+1]%2==1 and length%2==1) {opened = false; formed++;}
        else if (!opened and v[i]%2==1) {opened = true;length=1;}
        else length += 1;
        if (!opened and v[i]%2==1 and (i != n-1)) {opened = true;length=1;}
        if (i == n-1 and !opened and v[i]%2==1) {opened = true;length=1;}
        if (i == n-1 and opened and length%2==1 and v[i]%2==1) {opened = false; formed++;}
    }
    if (v[n-1]%2==0 or v[0]%2==0 or opened) {
        impossible = true;
    }
    if (impossible or (formed)%2 == 0) cout << "No";
    else cout << "Yes";    
    
    return 0;
}
