// https://neps.academy/br/course/estruturas-de-dados-(codcad)/lesson/fila

#include "bits/stdc++.h"
using namespace std;

vector<int> cup_queue;
set<int> removed;

int main(){
    int n; cin >> n;
    int p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        cup_queue.push_back(p);
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> p;
        removed.insert(p);
    }
    for (int p : cup_queue){
        if (removed.find(p)==removed.end()) cout << p << ' ';
    }

    return 0;
}
