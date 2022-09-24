#include "bits/stdc++.h"
using namespace std;

vector<vector<bool>> vis;
vector<vector<int>> v;
int n, m;

void DFS(int i, int c) // visit [i][c] and all their component
{
    if (vis[i][c]) return;
    else
    {
        vis[i][c] = true;
        if (v[i+1][c]) DFS(i+1, c);
        if (v[i-1][c]) DFS(i-1, c);
        if (v[i][c+1]) DFS(i, c+1);
        if (v[i][c-1]) DFS(i, c-1);
    }
}

int main() {
    cin >> n >> m;
    v = vector<vector<int>> (n+2, vector<int> (m+2));
    vis = vector<vector<bool>> (n+2, vector<bool> (m+2));
    int manchas = 0;

    for (int i = 0; i < n + 2; i++)
    {
        for (int c = 0; c < m + 2; c++)
        {
            if (i != 0 and i != n+1 and c != 0 and c != m+1)
            {
                cin >> v[i][c];
            }
            else
            {
                v[i][c] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int c = 1; c < m + 1; c++)
        {
            if (v[i][c] == 1 and !vis[i][c])
            {
                manchas++;
                DFS(i, c);
            }
        }
    }
    cout << manchas;

    return 0;
}
