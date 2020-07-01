#ifndef tree_h
#define tree_h

#include "bintree_eda.h"
#include <algorithm>
#include <math.h>
#include <iostream>
#include <stack>
#include <vector>

template <class T>
class tree : public bintree<T> {
	using Link = typename bintree<T>::Link;
	using TreeNode = typename bintree<T>::TreeNode;

	void check(tree<T> const& nodo, T& minimo) {
		T thisRoot = nodo.root();
		if (thisRoot < minimo)
			minimo = thisRoot;
	}

	void menor(tree<T> const& nodo, T & minimo) {
		if (nodo.empty()) {
			//nothing
		}
		else if (nodo.left().empty()) {
			check(nodo, minimo);
			menor(nodo.right(), minimo);
		}
		else if (nodo.right().empty()) {
			check(nodo, minimo);
			menor(nodo.left(), minimo);
		}
		else {
			check(nodo, minimo);
			menor(nodo.left(), minimo);
			menor(nodo.right(), minimo);
		}
	}

public:
	tree() : bintree<T>() {}
	tree(bintree<T> const& r) : bintree<T>(r) {}
	tree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		bintree<T>(l, e, r) {}

	T menor(T const& maximoDeEsteTipo) {
		T minimo = maximoDeEsteTipo;
		menor(*this, minimo);
		return minimo;
	}
};

template <typename T>
inline tree<T> leerTree(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerTree(vacio);
		auto dr = leerTree(vacio);
		return { iz, raiz, dr };
	}
}

#endif // !tree_h