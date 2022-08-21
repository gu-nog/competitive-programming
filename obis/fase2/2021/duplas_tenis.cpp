// https://olimpiada.ic.unicamp.br/pratique/p1/2021/f2/tenis

#include "bits/stdc++.h"
using namespace std;

int main(){
    int j[4];
    for (int i=0; i<4; i++){
        cin >> j[i];
    }
    sort(j, j+4);

    cout << abs((j[0]+j[3])-(j[1]+j[2]));
    
    return 0;
}
