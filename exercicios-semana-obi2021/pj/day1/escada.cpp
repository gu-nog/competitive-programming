// https://br.spoj.com/problems/JESCADA/
// stdc++
#include "bits/stdc++.h"
using namespace std;

int main(){
    int ps; cin >> ps;
    int active = 0;
    int used = 0;
    for (int i = 0; i < ps; i++) {
        int p; cin >> p;
        if (active < p){
            used += 10; active = p + 10;
        } else {
            used += 10-(active-p); active = p + 10;
        }
    }
    cout << used;
    
    return 0;
}
