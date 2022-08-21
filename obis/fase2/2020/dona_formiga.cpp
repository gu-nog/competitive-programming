// https://olimpiada.ic.unicamp.br/pratique/p1/2020/f2/formiga/

#include "bits/stdc++.h"
using namespace std;

int s, t, o; vector<int> alts; vector<vector<int>> tuneis; vector<int> dp;

int movis(int o, int p){
    if (dp[o]!=-1) return dp[o]+p;
    int r = p;
    for (int c : tuneis[o]){
        r = max(r, movis(c, p+1));
    }
    dp[o] = r-p;
    return r;
}

int main(){
    cin >> s >> t >> o;
    alts = vector<int> (s);
    dp = vector<int> (s);
    for (int i=0; i<dp.size(); i++){
        dp[i] = -1;
    }
    tuneis = vector<vector<int>> (s);
    for (int i=0; i<s; i++){
        cin >> alts[i];
    }
    for (int i=0; i<t; i++){
        int a, b;
        cin >> a >> b;
        if (alts[a-1] > alts[b-1]) tuneis[a-1].push_back(b-1);
        else if (alts[a-1] < alts[b-1]) tuneis[b-1].push_back(a-1);
    }
    cout << movis(o-1, 0);

    return 0;
}
