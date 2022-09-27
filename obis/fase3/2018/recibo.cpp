#include "bits/stdc++.h"
using namespace std;

int total, p;
int dp[21][101][101];

int laco(int nivel, int minimo, int maximo) // nível do laço(qtd aninhada) e começo(minimo) ate final(maximo)
{
    if (dp[nivel][minimo][maximo] != -1) return dp[nivel][minimo][maximo];
    if (nivel == p) return minimo <= maximo; // significa que o ultimo numero que falta é menor do que o número que falta
    // para somar o valor alvo
    else 
    {
        int ans = 0;
        for (int i = minimo; i <= maximo; i++)
        {
            ans += laco(nivel + 1, i + 1, maximo - i);
        }
        return dp[nivel][minimo][maximo] = ans;
    }
}

int main()
{
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 101; j++)
            for (int k = 0; k < 101; k++)
                dp[i][j][k] = -1;
    
    cin >> total >> p;
    cout << laco(1, 1, total);

    return 0;
}
