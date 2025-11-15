#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5;
const ll INF = 1e18;
const int LOG = 30;

ll dp[MAXN], a[MAXN];
int last[LOG+1], p[LOG+1];
// last[b] = última vez (mais à direita) que o bit 2^b apareceu no prefixo de [1; i] atual
// p[i] = bit b que é o i-ésimo ao ordená-los por aparição decrescente (último / mais à direita para primeiro / mais à esquerda)

struct Node {
    ll mn;

    Node (ll _mn=INF): mn(_mn) {}

    Node operator+(Node right) {
        Node left = *this;
        return Node(min(left.mn, right.mn));
    }
};

struct SEG {
    vector<Node> seg; int n;

    SEG(int _n=0) {
        n = 1;
        while (n < _n) n <<= 1;
        seg = vector<Node> (2*n);
    }

    int getLeft(int v) {
        return 2*v;
    }

    int getRight(int v) {
        return 2*v+1;
    }

    void put(int v, int l, int r, int i, ll val) {
        if (l == r) {
            seg[v].mn = min(seg[v].mn, val);
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) put(getLeft(v), l, m, i, val);
        else put(getRight(v), m+1, r, i, val);
        seg[v] = seg[getLeft(v)] + seg[getRight(v)];
    }

    Node rng(int v, int l, int r, int ll, int rr) {
        if (ll <= l and r <= rr) {
            return seg[v];
        }
        if (r < ll or rr < l) return Node();
        int m = (l + r) / 2;
        return rng(getLeft(v), l, m, ll, rr) + rng(getRight(v), m+1, r, ll, rr);
    }
};

bool cmp(int i, int j) {
    return last[i] > last[j];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i=0; i<=LOG; i++) p[i] = i, last[i] = -1;

    int n, k; cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    vector<SEG> segs(k-1, SEG((n+k-2) / (k-1)));

    for (int i=0, querySegId = k-2; i<n; i++, querySegId = (querySegId + 1) % (k-1)) {
        dp[i] = INF;

        for (int b=0; b<=LOG; b++) {
            if (((1 << b) & a[i]) != 0) last[b] = i;
        }

        sort(p, p+LOG+1, cmp);

        int r=i-1, rngOr = 0;
        vector<tuple<int, int, int>> rngsOr; // {l, r, OR} tal que para as dp's em [l, r] somaremos OR
        for (int j=0; j<=LOG; j++) { 
            if (last[p[j]] == -1) break;

            int l = last[p[j]];
            rngsOr.emplace_back(l, r, rngOr);

            r = l-1;

            rngOr |= (1 << p[j]);
            while (j < LOG and last[p[j]] == last[p[j+1]]) {
                rngOr |= (1 << (p[++j]));
            }
        }
        rngsOr.emplace_back(0, r, rngOr);

        for (auto [l, r, rngOr] : rngsOr) {
            int idxL = l / (k-1) + ((l % (k-1)) > querySegId),
                idxR = r / (k-1) - ((r % (k-1)) < querySegId);

            if (idxL <= idxR)
                dp[i] = min(  // transição
                    dp[i],
                    segs[querySegId].rng(1, 0, segs[querySegId].n-1, idxL, idxR).mn + rngOr
                );
        }

        if (i % (k-1) == 0) {  // base
            dp[i] = min(dp[i], (ll)rngOr);
        }

        segs[i % (k-1)].put(1, 0, segs[i % (k-1)].n-1, i / (k-1), dp[i]);
    }
    cout << dp[n-1] << '\n'; // resposta

    return 0;
}
