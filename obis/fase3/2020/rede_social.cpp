// https://olimpiada.ic.unicamp.br/pratique/p1/2020/f3/rede/

#include "bits/stdc++.h"
using namespace std;

int main() {
    int ms; cin >> ms;
    int frs[ms];
    for (int i = 0; i < ms; i++)
    {
        cin >> frs[i];
    }
    
    sort(frs, frs + ms);

    int fr = 0;
    for (int i = ms - 1; i >= 0; i--)
    {
        fr++;
        if (frs[i] < fr) 
        {
            cout << fr-1;
            break;
        }
    }
    

    return 0;
}
