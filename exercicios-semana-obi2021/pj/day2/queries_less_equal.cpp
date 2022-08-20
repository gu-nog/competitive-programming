// https://codeforces.com/problemset/problem/600/B
// Observation: I couldn't do an solution that satisfies the time limit

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    int m; int n;
    cin >> m >> n; ll v[m]; int qtd; ll q; ll qs[n];
    for (int i = 0; i < m; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> qs[i];
    sort(v, v+m);
    for (int i=0; i<n; i++){
        cout << upper_bound(v, v+m, qs[i]) - v << ' ';
    }
    return 0;
}
