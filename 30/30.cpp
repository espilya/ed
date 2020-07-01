#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "bintree_eda.h"

using namespace std;


bintree<int> arbol(const std::vector<int>& v, const std::pair<int, int>& indices) {

	if (indices.first > indices.second) return {};
	else {
		int i = indices.first + 1;
		int ac = v[indices.first];
		while (i <= indices.second && ac > v[i]) ++i;
		bintree<int> izq = arbol(v, { indices.first + 1, i - 1 });
		bintree<int> der = arbol(v, { i, indices.second });

		return { izq , ac , der };
	}
	

}


void resolver() {
	std::string linea;
	while (getline(cin, linea)) {
	

		int dato;
		std::vector<int> entrada;
		std::pair<int, int> indices;
		std::stringstream ss(linea);

		while (ss >> dato)
			entrada.push_back(dato);

		bintree<int> tree = arbol(entrada, { 0, entrada.size() - 1 });

		auto sol = tree.postorder();

		cout << sol[0];
		for (int i = 1; i < sol.size(); ++i)
			cout << " " << sol[i];
		cout << "\n";
	}
}


int main() {

	//int n; cin >> n;
	//char aux; cin.get(aux);
	//for (int i = 0; i < n; i++) {
		resolver();
	//}
}
