
// Ilya Lapshin

#include <iostream>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

using namespace std;



typedef struct {
	int max;
	int act;
}tPair;


tPair caminoPares(bintree<int> arbol) {
	// CASOS BASE
	if (arbol.empty()) // si es vacio
		return { 0,0 };
	else if (arbol.left().empty() && arbol.right().empty()) { // si sus hijos son vacios
		if (arbol.root() % 2 != 0)
			return { 0,0 };
		else
			return { 1,1 };
	}

	// RECURSION
	else {
		tPair der, izq;
		izq = caminoPares(arbol.left()); // nodo derecho
		der = caminoPares(arbol.right()); // nodo izquierdp

		if (arbol.root() % 2 == 0) { // si es par
			int maximo = max(izq.act, der.act) + 1;
			return { izq.act + der.act + 1, maximo }; // par = se suman los dos maximos + 1 // se coge el maximo de los actuales +1
		}
		else return  { max(izq.max, der.max), 0 }; // si es impar 
	}
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	cout << caminoPares(arbol).max << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
