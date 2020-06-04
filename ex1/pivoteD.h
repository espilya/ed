#ifndef pivote_H
#define pivote_H


#include <iostream>
#include "deque_eda.h"
#include <string>


template <class T>
class fat : public deque<T> {
	using Nodo = typename deque<T>::Nodo;

	//struct Nodo {
	//	Nodo() : ant(nullptr), sig(nullptr) {}
	//	Nodo(T const& elem, Nodo* ant, Nodo* sig) : elem(elem), ant(ant), sig(sig) {}
	//	T elem;
	//	Nodo* ant;
	//	Nodo* sig;
	//};

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

	void ampliar(fat<T>& listaNueva) {
		Nodo* nodo2 = listaNueva.fantasma->sig;
		bool principio = true;
		while (listaNueva.nelems != 0) {
			if (principio) {
				insertar(this->fantasma, this->fantasma->sig, nodo2);
			}
			else {
				//insertar(this->fantasma, this->fantasma->sig, nodo2);
				insertar(this->fantasma->ant, this->fantasma, nodo2);
			}
			listaNueva.nelems--;
			nodo2 = listaNueva.fantasma->sig;
			principio = !principio;
		}
	}

	void show() {
		Nodo* iter = this->fantasma->sig;
		while (iter != this->fantasma) {
			std::cout << iter->elem << " ";
			iter = iter->sig;
		}
		std::cout << '\n';
	}

};

#endif