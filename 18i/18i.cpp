#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "bintree_eda.h"

using namespace std;

typedef struct {
	int nodos;
	int hojas;
	int altura;
}tTrio;

tTrio resolver(bintree<char> const& arbol) {

	if (arbol.empty()) // si es vacio
		return { 0,0,0 };
	else if (arbol.left().empty() && arbol.right().empty()) { // si sus hijos son vacios
		return { 1, 1, 1 };
	}
	//else if (arbol.left().empty()) { // si sus hijos son vacios
	//	tTrio der, izq;
	//	der = resolver(arbol.right()); // nodo izquierdo

	//	return  { der.hojas + 1, der.hojas , der.altura + 1 };
	//}
	//else if (arbol.right().empty()) { // si sus hijos son vacios
	//	tTrio der, izq;
	//	izq = resolver(arbol.left()); // nodo derecho

	//	return  { izq.hojas + 1, izq.hojas , izq.altura + 1 };
	//}
	else {
		tTrio der, izq;
		izq = resolver(arbol.left()); // nodo derecho
		der = resolver(arbol.right()); // nodo izquierdo

		return  { izq.nodos + der.nodos + 1, izq.hojas + der.hojas, max(izq.altura, der.altura) + 1 };
	}

}


int main() {

	int n; cin >> n;
	//char aux; cin.get(aux);
	for (int i = 0; i < n; i++) {
		bintree<char> arbol = leerArbol('.');
		tTrio rel = resolver(arbol);
		//num nodos
		cout << rel.nodos << " ";
		//num hojas
		cout << rel.hojas << " ";
		//altura
		cout << rel.altura << '\n';
	}


}
