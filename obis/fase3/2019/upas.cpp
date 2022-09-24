#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> removed;
    tuple<int, int, int> nc[m];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        nc[i] = make_tuple(u + v, v, u);
    } 
    sort(nc, nc + m);
    for (int i = m-1; i >= 0; i--)
    {
        int v = get<1>(nc[i]);
        int u = get<2>(nc[i]);
        if (v > u) {
            if (removed.count(v) == 1)
            {
                continue;
            }
            removed.insert(u);
        } else {
            if (removed.count(u) == 1)
            {
                continue;
            }
            removed.insert(v);
        }
    }
    bool r[n + 1];
    int c = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (i == n+1) r[i] = -2;
        else if (removed.count(i) == 0)
        {
            r[i] = true;
            c++;
        }
        else
        {
            r[i] = false;
        }
    }
    cout << c << endl;
    for (int i = 1; i <= n; i++)
    {
        if (r[i]) cout << i << ' ';
    }
    
    
    

    return 0;
}
