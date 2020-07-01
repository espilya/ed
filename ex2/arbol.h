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

	bool sinHijos(tree<T> const arbol) {
		return  arbol.left().empty() && arbol.right().empty();
	}

	int fronteras(tree<T> const& arbol, std::vector<int>& lista) {
		if (arbol.empty()) {
			return 0;
		}
		else if (sinHijos(arbol)) {
			lista.push_back(arbol.root());
			return 1;
		}
		else {
			return (fronteras(arbol.left(), lista) + fronteras(arbol.right(), lista));
		}
	}

public:
	tree() : bintree<T>() {}
	tree(bintree<T> const& r) : bintree<T>(r) {}
	tree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		bintree<T>(l, e, r) {}

	std::vector<int> fronteras() {
		std::vector<int> frontera;
		fronteras(*this, frontera);
		return frontera;
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