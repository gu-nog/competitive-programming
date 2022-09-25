#include "bits/stdc++.h"
using namespace std;

int main()
{
    int ataque1, defesa1;
    int ataque2, defesa2;
    cin >> ataque1 >> defesa1;
    cin >> ataque2 >> defesa2;
    bool desmaio1 = defesa1 != ataque2;
    bool desmaio2 = defesa2 != ataque1;
    if (desmaio1 and !desmaio2) cout << 2;
    else if (!desmaio1 and desmaio2) cout << 1;
    else cout << -1;
    return 0;
}
