#ifndef tree_h
#define tree_h

#include "bintree_eda.h"
#include <algorithm>
#include <math.h>
#include <iostream>

template <class T>
class tree : public bintree<T> {
	using Link = typename bintree<T>::Link;
	using TreeNode = typename bintree<T>::TreeNode;

	bool sinHijos(tree<T> const arbol) {
		return  arbol.left().empty() + arbol.right().empty();
	}
		

public:
	tree() : bintree<T>() {}
	tree(bintree<T> const& r) : bintree<T>(r) {}
	tree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		bintree<T>(l, e, r) {}


	int nodos(tree<T> const& arbol) {
		if (arbol.empty()) {
			return 0;
		}
		else {
			return (nodos(arbol.left()) + nodos(arbol.right()) + 1);
		}
	}

	int hojas(tree<T> const& arbol) {
		if (arbol.empty()) {
			return 0;
		}
		else if (sinHijos(arbol)) {
			return 1;
		}
		else {
			return (hojas(arbol.left()) + hojas(arbol.right()));
		}
	}

	int altura(tree<T> const& arbol) {
		if (arbol.empty()) {
			return 0;
		}
		else {
			return std::max(altura(arbol.left()), altura(arbol.right())) + 1;
		}
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