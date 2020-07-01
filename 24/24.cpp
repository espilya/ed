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


bool solve(const bintree<char>& izq, const bintree<char>& der) {
	if (izq.empty() && der.empty()) return true;
	else if (izq.empty() && !der.empty()) return false;
	else if (!izq.empty() && der.empty()) return false;
	else {
		bool simIz, simDr;
		simIz = solve(izq.left(), der.right());
		simDr = solve(izq.right(), der.left());

		return simIz && simDr;
	}
}


void resolver() {
	bool ok = true;
	bintree<char> tree = leerArbol('.');
	vector<int> left;
	vector<int> right;

	ok = solve(tree.left(), tree.right());

	cout << (ok? "SI":"NO") <<'\n';
}


int main() {

	int n; cin >> n;
	//char aux; cin.get(aux);
	for (int i = 0; i < n; i++) {
		resolver();
	}
}
