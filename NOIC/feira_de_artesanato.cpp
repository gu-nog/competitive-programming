#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXT = 1e5 + 1;
const int MAXN = 1e5;

multiset<int> byType[MAXT];
multiset<pair<int, int>> allTypes;

ll ans = 0;
int prices[MAXN], types[MAXN];

void remove(pair<int, int> prod) {
    int price = prod.first, type = prod.second;
    allTypes.erase(allTypes.find({price, type}));
    byType[type].erase(byType[type].find(price));
    ans += price;
}

void add(pair<int, int> prod) {
    int price = prod.first, type = prod.second;
    allTypes.insert(prod);
    byType[type].insert(price);
}

int main() {
    int n, qtyTypes; cin >> n >> qtyTypes;

    for (int i=0; i<n; i++) cin >> types[i];
    for (int i=0; i<n; i++) cin >> prices[i];

    for (int i=0; i<n; i++) add({prices[i], types[i]});

    int c; cin >> c;
    for (int i=0; i<c; i++) {
        int type; cin >> type;
        if (type == 0) {
            if (allTypes.empty()) continue;
            remove(*allTypes.begin());
        } else {
            if (byType[type].empty()) continue;
            remove({*byType[type].begin(), type});
        }
    }
    cout << ans << '\n';

    return 0;
}
