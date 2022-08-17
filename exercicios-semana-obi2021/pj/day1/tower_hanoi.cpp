// https://cses.fi/problemset/task/2165/

#include "bits/stdc++.h"
using namespace std;

int min(int n) {
    if (n==1) return 1;
    else return (2*min(n-1))+1;
}

void hanoi(int o, int d, int a, int qtd){
    if(qtd!=0) {
        hanoi(o, a, d, qtd-1);
        cout << o + 1 << ' ' << d + 1 << endl;
        hanoi(a, d, o, qtd-1);
    }
}

int main(){
    int n; cin >> n;
    cout << min(n) << endl;
    hanoi(0, 2, 1, n);
    return 0;
}
