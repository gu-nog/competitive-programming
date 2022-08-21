// https://olimpiada.ic.unicamp.br/pratique/p1/2021/f2/recorde/

#include "bits/stdc++.h"
using namespace std;

int main(){
    int r; int rm; int ro; cin >> r >> rm >> ro;
    if (r < rm) cout << "RM"; else cout << "*"; cout << endl;
    if (r < ro) cout << "RO"; else cout << "*"; cout << endl;

    return 0;
}
