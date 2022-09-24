// https://olimpiada.ic.unicamp.br/pratique/p1/2021/f3/festa/

#include "bits/stdc++.h"
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    set<int> removed;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        for (int c = t; c <= n; c+=t)
        {
            removed.insert(c);
        }
    }
    int c = 0;
    for (int i = 1; i < n && c <= 10000; i++)
    {
        if (removed.count(i) == 0)
        {
            cout << i << endl;
            c++;
        }
    }
    
    
    return 0;
}
