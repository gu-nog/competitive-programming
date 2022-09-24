// https://olimpiada.ic.unicamp.br/pratique/p1/2021/f3/casamento/
#include "bits/stdc++.h"
using namespace std;

int main(){
    string a; string b;
    cin >> a >> b;
    int len_a = a.end() - a.begin();
    int len_b = b.end() - b.begin();
    string result_a = "";
    string result_b = "";
    if (len_a > len_b)
    {
        for (int i = 0; i < len_a; i++)
        {
            int diff = len_a - len_b;
            if (i < diff)
            {
                result_a += a[i]; // because never is shorter than 0
            }
            else
            {
                if (a[i] > b[i - diff])
                {
                    result_a += a[i];
                }
                else if (a[i] < b[i - diff])
                {
                    result_b += b[i - diff];
                }
                else
                {
                    result_a += a[i];
                    result_b += b[i - diff];
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < len_b; i++)
        {
            int diff = len_b - len_a;
            if (i < diff)
            {
                result_b += b[i]; // because never is shorter than 0
            }
            else
            {
                if (a[i - diff] > b[i])
                {
                    result_a += a[i - diff];
                }
                else if (a[i - diff] < b[i])
                {
                    result_b += b[i];
                }
                else
                {
                    result_a += a[i - diff];
                    result_b += b[i];
                }
            }
        }
    }
    if (result_a == "") result_a = "-1";
    if (result_b == "") result_b = "-1";
    cout << min(result_a, result_b) << ' ' << max(result_a, result_b) << endl;
    
    return 0;
}
