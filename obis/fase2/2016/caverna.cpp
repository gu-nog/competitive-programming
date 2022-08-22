// https://olimpiada.ic.unicamp.br/pratique/p1/2016/f2/caverna/

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    int m; int f; cin >> m >> f;
    pair<int, int> dists[m+1];
    dists[m] = make_pair(1e8+10, 1e8+10);
    for (int i = 0; i < m; i++) {
        int d; cin >> d;
        dists[i] = make_pair(min(d, f-d), max(d, f-d));
    }
    int m_depth = 0; bool imp = false; long long int tot = 0;
    for (int i = 0; i < m; i++) {
        if (dists[i].first < m_depth) {
            if (dists[i].second < m_depth) imp = true;
            else tot += m_depth = dists[i].second; 
        } else tot += m_depth = dists[i].first;
    }
    if (!imp) cout << tot;
    else cout << -1;
    
    return 0;
}
