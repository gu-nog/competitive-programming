// https://olimpiada.ic.unicamp.br/pratique/p1/2021/f2/robo/

#include "bits/stdc++.h"
using namespace std;

int main(){
    int ests; int cmds; int nearest; int actual = 1; int cmd; int c=0;
    cin >> ests >> cmds >> nearest;
    if (nearest == 1) c++;
    for (int i=0; i<cmds; i++){
        cin >> cmd;
        actual += cmd;
        if (actual > ests) actual = 1;
        if (actual < 1) actual = ests;
        if (actual == nearest) c++;
    }
    cout << c;

    return 0;
}
