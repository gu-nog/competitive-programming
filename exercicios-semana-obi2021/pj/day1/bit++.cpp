// https://codeforces.com/contest/282/problem/A
// stdc++
#include "bits/stdc++.h"
using namespace std;

int main(){
    int r = 0; 
    int ops; cin >> ops;
    for (int i = 0; i < ops; i++)
    {
        string op; cin >> op;
        if (op[1] == '+') r += 1;
        else r -= 1;
    }
    cout << r;
    
    return 0;
}
