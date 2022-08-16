// https://neps.academy/br/course/programacao-basica-(codcad)/lesson/torres-de-hanoi

#include "bits/stdc++.h"
using namespace std;


int hanoi(int n){
    if (n == 0) return 0;
    return 2 * hanoi(n-1) + 1;
}

int main(){
    int n; cin >> n;
    int c = 1;
    while (n != 0){
        cout << "Teste " << c << endl << hanoi(n) << endl << endl;
        cin >> n; c++;
    }
    return 0;
}
