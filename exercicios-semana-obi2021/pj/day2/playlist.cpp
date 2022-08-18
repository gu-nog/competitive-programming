// https://cses.fi/problemset/result/4454646/

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

set<int> lasts;
queue<int> last_saw;

int main(){
    int n; cin >> n;
    int c = 0;
    int m = 0;
    for (int i = 1; i <= n; i++) {
        int id; cin >> id;
        if (lasts.count(id) == 0){
            lasts.insert(id);
            last_saw.push(id);
            c += 1;
            m = max(c, m);
        } else {
            m = max(c, m);
            int front = last_saw.front();
            lasts.erase(front);
            last_saw.pop();
            c-=1;
            while (front != id){
                c-=1;
                front = last_saw.front();
                last_saw.pop();
                lasts.erase(front);
            }
            lasts.insert(id);
            last_saw.push(id);
            c+=1;
        }
    }
    cout << m;
    return 0;
}
