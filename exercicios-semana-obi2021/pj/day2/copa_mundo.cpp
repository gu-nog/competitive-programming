// https://neps.academy/br/course/estruturas-de-dados-(codcad)/lesson/copa-do-mundo

#include "bits/stdc++.h"
using namespace std;

vector<int> turns[4];
char index_countries[17] = "ABCDEFGHIJKLMNOP";

int main(){
    for (int i = 0; i < 4; i++){
        if (i==0){
            for (int i = 0; i < 16; i+=2) {
                int m; int n; cin >> m >> n;
                if (m > n) turns[0].push_back(i);
                else turns[0].push_back(i+1);
            }
        } else {
            for (int c = 0; c < int(turns[i-1].size()); c+=2)
            {
                int m; int n; cin >> m >> n;
                if (m > n) turns[i].push_back(turns[i-1][c]);
                else turns[i].push_back(turns[i-1][c+1]);
            }
        }
    }
    cout << index_countries[turns[3][0]];
    
    return 0;
}
