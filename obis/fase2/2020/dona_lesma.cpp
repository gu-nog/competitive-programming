// https://olimpiada.ic.unicamp.br/pratique/p1/2020/f2/lesma

#include "bits/stdc++.h"
using namespace std;

int main(){
    int a, s, d; int now=0, c = 0;
    cin >> a >> s >> d;
    while (a > now){
        now += s; c++;
        if (now >= a) {cout << c; break;}
        now -= d;
    }

    return 0;
}
