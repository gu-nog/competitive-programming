#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5;
const ll INF = 1e18;

ll dp[MAXN], a[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) {
        ll prefOr = 0;
        dp[i] = INF;
        for (int j=i-1, pt = i; j>=-1; j-=(k-1)) {
            while (pt >= 0 and pt > j) prefOr |= a[pt--];
            dp[i] = min(dp[i], (j == -1 ? 0 : dp[j]) + prefOr);
        }
    }
    cout << dp[n-1] << '\n';

    return 0;
}
