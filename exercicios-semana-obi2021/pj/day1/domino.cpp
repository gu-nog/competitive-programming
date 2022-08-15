// https://codeforces.com/problemset/problem/50/A
// stdc++
#include "bits/stdc++.h"
using namespace std;

int main(){
    int m, n; cin >> m >> n;
    if (m%2 == 0){
        cout << m/2 * n;
    }
    else {
        cout << ((m-1)/2 * n) + n/2; // because the last column will be covered by a half of the height n of dominoes on vertical axis
    }
    
    return 0;
}
