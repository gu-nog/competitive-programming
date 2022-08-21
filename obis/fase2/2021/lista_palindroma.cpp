// https://olimpiada.ic.unicamp.br/pratique/p1/2021/f2/lista/

#include "bits/stdc++.h"
using namespace std;

int main(){
    int n; cin >> n; vector<int> v(n); int ops = 0;
    for (int i=0; i < n; i++) cin >> v[i];
    for (int l=0, r=n-1; l < r; l++, r--){
        if (v[l] != v[r]){
            if (v[l] < v[r]){
                v[l+1] += v[l];
                ops++; r++;
            } else {
                v[r-1] += v[r];
                ops++; l--;
            }
        }
    }
    cout << ops;
    
    return 0;
}
