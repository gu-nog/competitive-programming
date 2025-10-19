#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;

int a[MAXN], allDiags[2*MAXN], freq[MAXN];
map<int, int> mpDiag;

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        allDiags[2*i] = i + a[i];
        allDiags[2*i+1] = i + 1;
    }

    sort(allDiags, allDiags + 2*n);
    for (int i=0; i<2*n; i++)
        mpDiag[allDiags[i]] = i;

    int ans = 0, tmp = 0, pt = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == 0) continue;
        while (pt < mpDiag[i+1])
            tmp -= freq[pt++];
        ans = max(ans, tmp + 1);

        if (mpDiag[i+a[i]] <= pt) continue;
        else freq[mpDiag[i + a[i]]]++, tmp++;
    }

    cout << ans << '\n';

    return 0;
}
