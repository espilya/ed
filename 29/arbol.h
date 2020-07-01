#ifndef tree_h
#define tree_h

#include "bintree_eda.h"
#include <algorithm>
#include <math.h>
#include <iostream>
#include <stack>
#include <vector>


typedef struct {
	int max;
	bool busq;
	int min;
}tArb;

template <class T>
class tree : public bintree<T> {
	using Link = typename bintree<T>::Link;
	using TreeNode = typename bintree<T>::TreeNode;

	void check(tree<T> const& nodo, T& minimo) {
		T thisRoot = nodo.root();
		if (thisRoot < minimo)
			minimo = thisRoot;
	}

	tArb diam(tree<int> const& nodo) {
		// CASOS BASE
		if (nodo.empty()) // si es vacio
			return { 0, true, 0 };
		else if (nodo.left().empty() && nodo.right().empty()) { // si sus hijos son vacios
			return { nodo.root(), true, nodo.root() };
		}

		// RECURSION
		else {
			bool ok;
			tArb der, izq;
			izq = diam(nodo.left()); // nodo derecho
			der = diam(nodo.right()); // nodo izquierdp
			if (izq.max == 0) {
				ok = (nodo.root() < der.max) && der.busq;
				return { std::max(nodo.root(), der.max), ok, std::min(nodo.root(), der.min) };
			}
			else if (der.max == 0) {
				ok = (nodo.root() < izq.min) && izq.busq;
				return { std::max(nodo.root(), izq.max), ok, std::min(nodo.root(), izq.min) };
			}
			else {
				ok = (nodo.root() > izq.max) && (nodo.root() < der.max) && izq.busq && der.busq;
				int maximo = std::max(izq.max, der.max);
				int minimo = std::min(izq.min, der.min);
				return { std::max(nodo.root(), maximo), ok, std::min(nodo.root(), der.min) };
			}
		}
	}

public:
	tree() : bintree<T>() {}
	tree(bintree<T> const& r) : bintree<T>(r) {}
	tree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		bintree<T>(l, e, r) {}

	bool diam() {
		tArb busq;
		busq = diam(*this);
		return busq.busq;
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