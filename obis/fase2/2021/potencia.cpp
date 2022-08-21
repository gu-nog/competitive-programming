// https://olimpiada.ic.unicamp.br/pratique/p1/2021/f2/potencia

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    int n; ll r = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        string num; cin >> num; int base=0;
        int e = num[num.size()-1] - 48; num.pop_back();
        for (int c=1; c <= int(num.size()); c++){
            base += (pow(10, int(num.size()-c))) * (num[c-1] - 48);
        }
        r += pow(base, e);
    }
    cout << r;
    
    return 0;
}
/* e. g. 3^1001 = 3 * 3^1000 = 3 * ((3*3)^500) = 3 * (9^500) = 3 * ((9*9)^250) ....
ll pow(ll x, ll e) {
    if (e == 0) return 1;
    if (e%2==0) return pow(x*x, e/2); // x^e = x²^e/2
    else return x * pow(x, e-1);
}
*/
