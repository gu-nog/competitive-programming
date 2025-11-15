#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;

int a[MAXN], freq[MAXN];
map<int, int> mpDiag;

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans = 0, tmp = 0;
    for (int i=0; i<n; i++) {
        // manter diags máximas >= i+1
        tmp -= freq[i];
        if (a[i] == 0) continue;
        ans = max(ans, tmp + 1);

        if (i+a[i] < n) freq[i + a[i]]++;
        tmp++;
    }

    cout << ans << '\n';

    return 0;
}
