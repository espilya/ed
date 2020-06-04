#ifndef order_H
#define order_H

#include "deque_eda.h"


template <class T>
class orderQueue : public deque<T> {
	using Nodo = typename deque<T>::Nodo;

	/*struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const& el, Nodo* si = nullptr) : elem(el), sig(si) {}
		T elem;
		Nodo* sig;
	};*/
private:


	void insertar(Nodo* a, Nodo* b, Nodo* insertar) {
		Nodo* insertarSig = insertar->sig;
		Nodo* insertarAnt = insertar->ant;
		insertarAnt->sig = insertarSig;
		insertarSig->ant = insertarAnt;

		a->sig = insertar;
		b->ant = insertar;

		insertar->sig = b;
		insertar->ant = a;

	}

public:

	void merge(orderQueue<T>& listaNueva) {
		Nodo* prt1 = this->fantasma->sig;
		Nodo* prt2 = listaNueva.fantasma->sig;
		while (prt1->sig != this->fantasma && prt2->sig != listaNueva.fantasma) {
			if (prt1->elem < prt2->elem && prt1->sig->elem > prt2->elem) {
				insertar(prt1, prt1->sig, prt2);
				prt1 = prt2;
				prt2 = listaNueva.fantasma->sig;
			}
			else if (prt1->elem >= prt2->elem) {
				insertar(prt1->ant, prt1, prt2);
				prt1 = prt2;
				prt2 = listaNueva.fantasma->sig;
			}
		}
		if (prt1->sig == this->fantasma) {
			Nodo* iter = prt2;
			while (iter != listaNueva.fantasma) {
				this->push_back(iter->elem);
				iter = iter->sig;
			}
		}
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