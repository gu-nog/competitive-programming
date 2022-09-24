#include "bits/stdc++.h"
using namespace std;

int main()
{
    int tot, parcelas;
    cin >> tot >> parcelas;
    int minimum = tot / parcelas;
    int qtd_max = tot - (parcelas * minimum);
    for (int i = 0; i < parcelas; i++)
    {
        if (i <= qtd_max - 1) cout << minimum + 1 << endl;
        else cout << minimum << endl;
    }
    

    return 0;
}
