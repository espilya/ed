#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "arbol.h"

using namespace std;



void resolver() {
	tree<int> tree = leerTree(-1);
	if (tree.empty()) {
		cout << "SI ";
	}
	else {
		if (tree.diam())
			cout << "SI ";
		else
			cout << "NO ";
	}
	cout << '\n';
}


int main() {

	int n; cin >> n;
	//char aux; cin.get(aux);
	for (int i = 0; i < n; i++) {
		resolver();
	}
}
