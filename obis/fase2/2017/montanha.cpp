// https://olimpiada.ic.unicamp.br/pratique/p1/2017/f2/montanha/

#include "bits/stdc++.h"
using namespace std;

int main(){
    int n; cin >> n; int m = 0, last; bool falling=false, second=false;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        m = max(m, a);
        if (a!=m and !falling) {
            falling = true;
            last=a;
        }
        if (falling){
            if (last < a){
                second=true;
                break;
            } else {
                last=a;
            }
        }
    }
    if (second) cout << "S";
    else cout << "N";
    

    return 0;
}
