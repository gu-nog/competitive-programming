// https://olimpiada.ic.unicamp.br/pratique/p1/2018/f2/capsulas

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    int c; ll target; cin >> c >> target; int coins[c]; ll r=0;
    for (int i = 0; i < c; i++) cin >> coins[i];
    int dia; int dl=0, dr=10e8+10;
    while (true){
        dia = (dl + dr)/2;
        r=0; for (int i = 0; i < c; i++) r += dia / coins[i];
        if (r==target) break;
        if (dl==dr or abs(dl-dr) <= 1) break;
        if (r > target) dr = dia;
        else dl = dia;
    } dia += 10; r=0; for (int i = 0; i < c; i++) r += dia / coins[i];
    while (r>=target){
        dia--; r=0;
        for (int i = 0; i < c; i++) r += dia / coins[i];
    }
    
    cout << dia+1;
     


    return 0;
}
