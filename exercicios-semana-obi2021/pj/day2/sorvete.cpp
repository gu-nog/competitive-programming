// https://neps.academy/br/course/estruturas-de-dados-(codcad)/lesson/sorvete

#include "bits/stdc++.h"
using namespace std;

vector<pair<int, bool>> beach;

int main(){
    int p; int s;
    cin >> p >> s;
    for (int i = 0; i < s; i++) {
        int start; int end;
        cin >> start >> end;
        beach.emplace_back(start, false);
        beach.emplace_back(end, true);
    }
    int opened = 0;
    int last = 0;
    for (pair<int, bool> flag : beach){
        if (flag.second == false){
            opened += 1;
            if (opened == 1){
                cout << flag.first << ' ';
            }
        } else {
            opened -= 1;
            if (opened == 0){
                cout << flag.second << endl;
            }
        }
    }
    

    return 0;
}
