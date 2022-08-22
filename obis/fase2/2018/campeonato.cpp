// https://olimpiada.ic.unicamp.br/pratique/p1/2018/f2/campeonato/

#include "bits/stdc++.h"
using namespace std;

vector<int> chave[5];

int main(){
    bool find=false;
    for (int i=0; i<16; i+=2) {
        int a, b; cin >> a >> b;
        if (min(a, b) == 1 and max(a, b)==9) {find = true; cout << "oitavas";}
        chave[0].push_back(a); chave[0].push_back(b);
    }
    for (int i = 1; i < 5; i++) {
        for (int c=0; c<chave[i-1].size() and !find; c+=2){
            int a=chave[i-1][c], b=chave[i-1][c+1];
            if (min(a, b) == 1 and max(a, b)==9) {
                find=true;
                if (i==1) cout << "oitavas";
                if (i==2) cout << "quartas";
                if (i==3) cout << "semifinal";
                if (i==4) cout << "final";
            }
            if (a == 1 or b==1) chave[i].push_back(1);
            else if (a==9 or b==9) chave[i].push_back(9);
            else (chave[i].push_back(a));
        }
    }
    

    return 0;
}
