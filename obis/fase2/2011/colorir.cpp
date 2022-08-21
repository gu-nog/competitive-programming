// https://olimpiada.ic.unicamp.br/pratique/p1/2011/f2/colorir/

#include "bits/stdc++.h"
using namespace std;

int x; int y; int painted = 1; vector<vector<int>> draw;

void view(int view_x, int view_y){
    vector<pair<int, int>> all = {
            make_pair(view_x+1, view_y-1), make_pair(view_x+1, view_y), make_pair(view_x+1, view_y+1),
            make_pair(view_x, view_y-1), make_pair(view_x, view_y+1),
            make_pair(view_x-1, view_y-1), make_pair(view_x-1, view_y), make_pair(view_x-1, view_y+1)
    };
    for (int i = 0; i < 8; ++i) {
        if (all[i].first <= x-1 && all[i].first >= 0 && all[i].second >= 0 && all[i].second <= y-1 && draw[all[i].first][all[i].second] == 0){
            painted++;
            draw[all[i].first][all[i].second] = 1;
            view(all[i].first, all[i].second);
        }
    }
}

int main() {
    int initial_x=-1; int initial_y = -1; int qtd_empty;
    cin >> x >> y >> initial_x >> initial_y >> qtd_empty;
    vector<vector<int>> temp(x, vector<int> (y, 0));
    draw = temp;
    for (int i = 0; i < qtd_empty; ++i) {
        int empty_x; int empty_y;
        cin >> empty_x >> empty_y;
        draw[empty_x-1][empty_y-1] = 1;
    }

    draw[initial_x-1][initial_y-1] = 1;
    view(initial_x-1, initial_y-1);

    cout << painted;

    return 0;
}
