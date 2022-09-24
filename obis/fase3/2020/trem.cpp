// https://olimpiada.ic.unicamp.br/pratique/p1/2020/f3/trem/

#include "bits/stdc++.h"
using namespace std;

int run(int len_fora, queue<pair<int, int>> trilhos) // trilhos (trilho, len)
{
    return 0;
}

int main() {
    // ada uma das K linhas seguintes descreve uma consulta, e contém dois inteiros X e T, que indicam respectivamente 
    // a estação pela qual Herculano quer que o trem entre e o comprimento do trem.
    int estacoes, trilhos;
    cin >> estacoes >> trilhos;
    vector<vector<pair<int, int>>> grafo(estacoes);
    for (int i = 0; i < trilhos; i++)
    {
        int a, b, len;
        grafo[a].emplace_back(b, len);
        grafo[b].emplace_back(a, len);
    }
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++)
    {
        int start, len;
        cin >> start >> len;
    }
}
