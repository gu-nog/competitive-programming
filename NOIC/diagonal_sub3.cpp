#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;

int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == 0) continue;
        int res = 1;
        for (int j=0; j<i; j++) {
            if (1 + i <= a[j] + j) res++;
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';

    return 0;
}
