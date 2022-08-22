// https://olimpiada.ic.unicamp.br/pratique/p1/2019/f2/ponto/

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll passo(ll p, ll step, ll v, ll next){
    if (next==0) return p;
    if (step==0) step = 1;
    else step*=2;
    return passo((v+step) * (v+step), step, v+(step), next-1);
}

int main(){
    ll steps; cin >> steps;
    cout << passo(4, 0, 2, steps);

    return 0;
}
