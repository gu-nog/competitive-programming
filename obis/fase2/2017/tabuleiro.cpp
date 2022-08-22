// https://olimpiada.ic.unicamp.br/pratique/p1/2017/f2/tabuleiro/

#include "bits/stdc++.h"
using namespace std;

int main(){
    int n; cin >> n; int table[n][n];
    for (int l=0; l<n; l++){
        for (int c=0; c<n; c++){
            cin >> table[l][c];
        }
    }
    for (int c=1; c<n; c++){
        for (int l=1; l<n; l++){
            if (table[l-1][c-1] + table[l-1][c] + table[l][c-1] >= 2) table[l][c] = 0;
            else table[l][c] = 1;
        }
    }
    cout << table[n-1][n-1];
    

    return 0;
}
