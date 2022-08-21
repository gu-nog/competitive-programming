// https://olimpiada.ic.unicamp.br/pratique/p1/2020/f2/estrada/

#include "bits/stdc++.h"
using namespace std;

int main(){
    int t, cities; cin >> t >> cities; int c[cities];
    for (int i=0; i<cities; i++) cin >> c[i];
    sort(c, c+cities);
    double m = 10e8;
    for (int i = 0; i < cities; i++) {
        if (i==0) m = min(m, c[i]+((c[i+1] - c[i])/2.0));
        else if (i==cities-1) m = min(m, abs((c[i]-((c[i] - c[i-1])/2.0)) - t));
        else m = min(m, abs(c[i]-(((c[i] - c[i-1])/2.0)) - (c[i]+((c[i+1] - c[i])/2.0))));
    }
    printf("%.2f", m);
    
    return 0;
}
