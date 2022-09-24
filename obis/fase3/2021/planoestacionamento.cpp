// 

#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, m; // vagas, clientes
    cin >> n >> m;
    bool vagas[n];
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v; v--;
        while (vagas[v] && v >= 0)
        {
            v--;
        }
        if (v == -1)
        {
            cout << i;
            return 0;
        }
        else
        {
            vagas[v] = true;
        }
    }
    cout << m;
    
    return 0;
}
