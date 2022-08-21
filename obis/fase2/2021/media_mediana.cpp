// https://olimpiada.ic.unicamp.br/pratique/p1/2021/f2/media

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    ll a; ll b; ll c;
    cin >> a >> b;
    ll target_avg = min(a, b);
    ll dist = max(a, b) - min(a, b);
    cout << target_avg - dist;
    
    return 0;
}
