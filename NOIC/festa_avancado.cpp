#include <bits/stdc++.h>
using namespace std;

int main() {
	int escola, supermercado, lojinha;
	cin >> escola >> supermercado >> lojinha;

	cout << min(
		abs(escola - supermercado) + abs(supermercado - lojinha) + abs(lojinha - escola), // supermercado primeiro
		abs(escola - lojinha) + abs(lojinha - supermercado) + abs(supermercado - escola)  // lojinha primeiro
	) << '\n';

	return 0;
}
