
#ifndef smartQueue_h
#define smartQueue_h

#include <iostream>
#include <string>
#include "deque_eda.h"



template <class T>
class smartQueue : public deque<T> {
	using Nodo = typename deque<T>::Nodo;

	//struct Nodo {
	//	Nodo() : ant(nullptr), sig(nullptr) {}
	//	Nodo(T const& elem, Nodo* ant, Nodo* sig) : elem(elem), ant(ant), sig(sig) {}
	//	T elem;
	//	Nodo* ant;
	//	Nodo* sig;
	//};
public:

	void ampliar(smartQueue<T>& listaNueva, const int& pos) {
		this->nelems += listaNueva.size();
		Nodo* nodoPrim;
		Nodo* nodoAnt;
		nodoPrim = this->fantasma;
		for (int i = 0; i < pos; i++) {
			nodoPrim = nodoPrim->sig;
		}
		nodoAnt = nodoPrim->sig;

		nodoPrim->sig = listaNueva.fantasma->sig;
		listaNueva.fantasma->ant->sig = nodoAnt;
		listaNueva.fantasma->sig->ant = nodoPrim;
		nodoAnt->ant = listaNueva.fantasma->ant;

		std::cout << this->nelems << std::endl;
	}

	void toString() {
		Nodo* iter = this->fantasma->sig;
		while (iter != this->fantasma) {
			std::cout << iter->elem << " ";
			iter = iter->sig;
		}
		std::cout << '\n';
	}

};

#endif