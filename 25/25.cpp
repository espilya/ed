#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "bintree_eda.h"

using namespace std;





int solve(const bintree<int>& nodo, int& navegables) {
	int caudal = 0;
	if (nodo.empty())
		return 1;
	else if (nodo.left().empty()) {
		caudal = solve(nodo.right(), navegables);
	}
	else if (nodo.right().empty()) {
		caudal = solve(nodo.left(), navegables);
	}
	else {
		caudal += solve(nodo.left(), navegables);
		caudal += solve(nodo.right(), navegables);
	}
	if (nodo.root() == -2) {
		return caudal;
	}
	else {
		caudal -= nodo.root();
		if (caudal >= 3) {
			navegables++;
		}
	}
	return caudal;
}



void resolver() {
	int navegables = 0;
	bool first = true;
	bintree<int> tree = leerArbol(-1);
	solve(tree, navegables);
	if (navegables > 0)
		navegables--;

	cout << navegables << '\n';
}


int main() {

	int n; cin >> n;
	//char aux; cin.get(aux);
	for (int i = 0; i < n; i++) {
		resolver();
	}
}
