#include "bits/stdc++.h"
using namespace std;

vector<set<int>> graph; // lines connected by one or more terminals
set<int> vis;
vector<vector<int>> linhas_t;

int DFS(int o, int d)
{
    for (int linha : linhas_t[d])
    {
        if (linha == o) return 0;
    }
    if (vis.count(o) == 1) return 1e8;
    vis.insert(o);
    int dificult = 1e8;
    for (int viz : graph[o])
    {
        dificult = min(dificult, DFS(viz, d) + 1);
    }
    return dificult;
}

int main()
{
    int t, l, o, d; cin >> t >> l >> o >> d;
    linhas_t = vector<vector<int>> (t);
    graph = vector<set<int>> (l);
    for (int i = 0; i < l; i++)
    {
        int terminais;
        cin >> terminais;
        for (int c = 0; c < terminais; c++)
        {
            int terminal;
            cin >> terminal;
            linhas_t[terminal - 1].push_back(i);
        }
    }

    for (int i = 0; i < t; i++)
    {
        for (int c = 0; c < linhas_t[i].size(); c++)
        {
            for (int j = 0; j < linhas_t[i].size() and j != c; j++)
            {
                graph[linhas_t[i][c]].insert(linhas_t[i][j]);
                graph[linhas_t[i][j]].insert(linhas_t[i][c]);
            }
        }
    }
    int minimum = 1e8;
    for (int i : linhas_t[o-1])
    {
        minimum = min(DFS(i, d-1) + 1, minimum);
        vis.clear();
    }
    
    cout << minimum;
    
    return 0;
}
