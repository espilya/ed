#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "bintree_eda.h"

using namespace std;


typedef struct box {
	int gen;
}box;



void resolver() {
	bintree<int> tree = leerArbol(-1);
	if (tree.empty()) {
		cout << "SI " << 0;
	}
	else {
		int sol = solve(tree);
		if (sol > 0)
			cout << "SI " << sol + 1;
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
