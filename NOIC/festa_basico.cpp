#include <bits/stdc++.h>
using namespace std;

int distancia(int ponto1, int ponto2) {
	if (ponto1 <= ponto2) { // ponto 1 está à esquerda do 2
		return ponto2 - ponto1;
	}
	return ponto1 - ponto2; // ponto 1 está à direita do 2
}

int main() {
	int escola, supermercado, lojinha;
	cin >> escola >> supermercado >> lojinha;

	// distância percorrida: escola -> supermercado -> lojinha -> escola
	int supermercado_primeiro = (
		distancia(escola, supermercado)
		+ distancia(supermercado, lojinha)
		+ distancia(lojinha, escola)
	);

	// distância percorrida: escola -> lojinha -> supermercado -> escola
	int lojinha_primeiro = (
		distancia(escola, lojinha)
		+ distancia(lojinha, supermercado)
		+ distancia(supermercado, escola)
	);

	if (supermercado_primeiro < lojinha_primeiro) {
		cout << supermercado_primeiro << '\n';
	} else {
		cout << lojinha_primeiro << '\n';
	}

	return 0;
}
