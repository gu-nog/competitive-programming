// https://olimpiada.ic.unicamp.br/pratique/p1/2017/f2/castelos

#include "bits/stdc++.h"
using namespace std;

vector<pair<int, vector<int>>> castles; set<int> vis;

bool paint(int act, int color, int target){
    if (act==target) {
        castles[act].first = color;
        return true;
    }
    for (int i : castles[act].second) {
        if (vis.count(i) == 0){
            vis.insert(i);
            if (paint(i, color, target)){
                castles[act].first = color;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m; cin >> n >> m; castles = vector<pair<int, vector<int>>> (n);
    for (int i = 0; i < n-1; i++) {
        int o, d; cin >> o >> d; o--; d--;
        castles[o].second.push_back(d);
        castles[d].second.push_back(o);
    }

    for (int i = 0; i < m; i++){
        int o, t, c; cin >> o >> t >> c; o--; t--;
        vis.clear();
        vis.insert(o);
        paint(o, c, t);
    }
    for (pair<int, vector<int>> i : castles) {
        cout << i.first << ' ';
    }
    

    return 0;
}
