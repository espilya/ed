#include "bintree_eda.h"
#include <iostream>

template <class T>
bintree<T> arbol(T vacio) {


	void leer() {
		T raiz;
		if (cin >> raiz && raiz != '/n') {
			if (raiz == '.') { // es un árbol vacío
				return {};
			}
			else { // leer recursivamente los hijos
				auto iz = leer(vacio);
				auto dr = leer(vacio);
				return { iz, raiz, dr };
			}
		}
	}
}