// https://olimpiada.ic.unicamp.br/pratique/p1/2021/f2/calculo/

#include "bits/stdc++.h"
using namespace std;

int sum_digits(int n){
    string n_str = to_string(n);
    int r = 0;
    for (int n : n_str){
        r += n - 48;
    }
    return r;
}

int main(){
    int s; int a; int b; int r = 0;
    cin >> s >> a >> b;
    while (a <= b){
        if (sum_digits(a) == s) r++;
        a++;
    }
    
    cout << r;
    
    
    return 0;
}
