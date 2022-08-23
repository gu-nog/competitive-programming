// https://olimpiada.ic.unicamp.br/pratique/p1/2016/f2/medalhas/

#include "bits/stdc++.h"
using namespace std;

int main(){
    pair<int, int> comps[3];
    for (int i = 0; i < 3; i++) {
        cin >> comps[i].first;
        comps[i].second = i;
    }
    sort(comps, comps+3);
    for (auto n : comps){
        cout << n.second + 1 << endl;
    }
    

    return 0;
}
