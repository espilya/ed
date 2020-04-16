
#include <iostream>
#include <string>
#include "queue_eda.h"


template <class T>
class smartQueue : public queue<T>
{

	//struct Nodo {
	//    Nodo() : sig(nullptr) {}
	//    Nodo(T const& el, Nodo* si = nullptr) : elem(el), sig(si) {}
	//    T elem;
	//    Nodo* sig;
	//};

	//Nodo* prim;
	//Nodo* ult;

	//int nelems;


public:

	smartQueue() : prim(nullptr), ult(nullptr), nelems(0) {}


	void ampliar(int pos, smartQueue<T> const& num) {
		int i = 1;
		Nodo * iter = prim;
		Nodo* aux, auxPrimero;
		while (i < pos && iter != nullptr) {
			iter = iter->sig;
			i++;
		}
		aux = iter->sig;
		iter->sig = num.prim;
		num.ult->sig = aux;
		num.prim = nullptr;
		num.ult = nullptr;

	}

	void toString() {
		Nodo* iter = prim;
		while (iter != nullptr) {
			std::cout << iter->elem << " ";
			iter = iter->sig;
		}
		std::cout << '\n';
	}

};