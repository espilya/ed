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

/*
1. La edad del padre siempre supera en al menos 18 a˜nos las edades de cada uno de los hijos(si
	existen).
	2. La edad del segundo hijo(si existe) es al menos dos a˜nos menos que la del primer hijo(no hay
		hermanos gemelos / mellizos en estos ´arboles).
	3. Los ´arboles geneal´ogicos de ambos hijos son tambi´en correctos.
*/
// 40 20 2 -1 -1 0 -1 -1 -1

int solve(bintree<int> const& nodo) {
	int cont;

	if (nodo.empty()) // si es vacio
		return -2;
	else if (nodo.left().empty() && nodo.right().empty()) { // si sus hijos son vacios
		return -1;
	}
	else {
		int thisYO = nodo.root();
		bool ok = true;
		int left, right;
		left = solve(nodo.left()); // nodo derecho
		right = solve(nodo.right()); // nodo left
		if ((left == -2) ^ (right == -2)) { // -- XOR --
			if (nodo.left().empty()) {
				if (nodo.right().root() <= thisYO - 18)
					return right + 1;
				else
					return -1;
			}
			else if(nodo.right().empty()) {
				if (nodo.left().root() <= thisYO - 18)
					return left+1;
				else
					return -1;
			}
			else
				return 222;
		}
		else if (left == -1 && right == -1) {
			if (nodo.right().root() <= thisYO - 18 && nodo.left().root() <= thisYO - 18) {
				if (nodo.left().root() >= nodo.right().root()+2) {
						return 1;
				}
				return 0;
			}
			return 0;
		}
		else if (left != -1 && right != -1) {
			if (nodo.right().root() <= thisYO - 18 && nodo.left().root() <= thisYO - 18) {
				if (nodo.left().root() >= nodo.right().root() + 2) {
					if (left > right)
						return (left + 1);
					else
						return (right + 1);
				}
				return 0;
			}
			return 0;
		}
		return 0;
	}

}


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
