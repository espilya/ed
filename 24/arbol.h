#ifndef tree_h
#define tree_h

#include "bintree_eda.h"
#include <algorithm>
#include <math.h>
#include <iostream>
#include <stack>
#include <vector>

typedef struct   EquipoRescate {
	EquipoRescate() : salvados(0), numEquipos(0) {};
	int salvados;
	int numEquipos;
}EquipoRescate;

template <class T>
class tree : public bintree<T> {
	using Link = typename bintree<T>::Link;
	using TreeNode = typename bintree<T>::TreeNode;

	bool sinHijos(tree<T> const arbol) {
		return  arbol.left().empty() && arbol.right().empty();
	}

	EquipoRescate fronteras(tree<T> const& arbol, EquipoRescate a) {
		if (arbol.empty()) {
			a.numEquipos = 0;
			a.salvados = 0;
			return a;
		}
		else if (sinHijos(arbol)) {
			if (arbol.root() == 0) {
				a.numEquipos = 0;
				a.salvados = 0;
			}
			else {
				a.numEquipos = 1;
				a.salvados = arbol.root();
			}
			return a;
		}
		else {
			EquipoRescate left;
			EquipoRescate right;
			left = fronteras(arbol.left(), a);
			right = fronteras(arbol.right(), a);

			a.numEquipos = left.numEquipos + right.numEquipos;

			if (left.salvados > right.salvados)
				a.salvados = left.salvados;
			else
				a.salvados = right.salvados;

			if (arbol.root() != 0) {
				if (a.numEquipos == 0)
					a.numEquipos = 1;
				a.salvados += arbol.root();
			} 
			return a;
		}
	}

public:
	tree() : bintree<T>() {}
	tree(bintree<T> const& r) : bintree<T>(r) {}
	tree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		bintree<T>(l, e, r) {}

	std::vector<int> fronteras() {
		std::vector<int> v;
		EquipoRescate equipo;
		equipo = fronteras(*this, equipo);
		v.push_back(equipo.numEquipos);
		v.push_back(equipo.salvados);
		return v;
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