#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    int ts; cin >> ts;
    for (int i = 0; i < ts; i++){
        ll n; cin >> n;
        cout << (n-1)*(-1) << ' ' << n << endl;
    }
    return 0;
}