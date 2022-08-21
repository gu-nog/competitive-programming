// https://olimpiada.ic.unicamp.br/pratique/p1/2011/f2/bale

#include "bits/stdc++.h"
using namespace std;

int main() {
    int qtd_participantes;
    map<int, int> after;
    cin >> qtd_participantes;
    int participantes[qtd_participantes];
    for (int i = 0; i < qtd_participantes; ++i) {
        cin >> participantes[i];
    }
    int possible = 0;
    for (int i = qtd_participantes-1; i >= 0; --i) {
        auto p = after.begin();
        while (p != after.end() && p->first < participantes[i]) {
            possible += 1;
            p++;
        }
        if (after[participantes[i]]) {
            after[participantes[i]] += 1;
        } else {
            after[participantes[i]] = 1;
        }
    }

    cout << possible;

    return 0;
}
