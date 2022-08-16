// https://neps.academy/br/course/programacao-basica-(codcad)/lesson/fibonacci
#include "bits/stdc++.h"
using namespace std;

int dp[35];

int fib(int n){
    if (dp[n] != 0) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}

int main(){
    int n; cin >> n;
    dp[0] = 1; dp[1] = 1;
    cout << fib(n);
    return 0;
}
