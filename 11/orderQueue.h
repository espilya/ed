#ifndef order_H
#define order_H

#include "queue_eda.h"


template <class T>
class orderQueue : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

	/*struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const& el, Nodo* si = nullptr) : elem(el), sig(si) {}
		T elem;
		Nodo* sig;
	};*/
private:


	void insert(Nodo* actual, Nodo* b, orderQueue<T>& listaNueva) {
		Nodo* sig = actual->sig;
		listaNueva.prim = b->sig;
		actual->sig = b;
		b->sig = sig;
		listaNueva.nelems--;
		this->nelems++;
	}

public:

	void merge(orderQueue<T>& listaNueva) {
		Nodo* ptr1 = this->prim;
		Nodo* ptr2 = listaNueva.prim;
		Nodo* sig1;
		while (ptr1->sig != nullptr && ptr2 != nullptr) {

			if (ptr1->sig != nullptr)
				sig1 = ptr1->sig;
			else
				sig1 = ptr1;
			if (ptr1->elem <= ptr2->elem && ptr2->elem <= sig1->elem) {
				insert(ptr1, ptr2, listaNueva);
				ptr2 = listaNueva.prim;
			}
			else if (ptr1->elem > ptr2->elem ) {
				insert(ptr1, ptr2, listaNueva);
				ptr2 = listaNueva.prim;
			}
			else {
				ptr1 = ptr1->sig;
			}
		}
		if (ptr1->sig == nullptr) {
			Nodo* iter = listaNueva.prim;
			while (iter != nullptr) {
				this->push(iter->elem);
				iter = iter->sig;
			}
		}
	}

	void toString() {
		Nodo* iter = this->prim;
		while (iter != nullptr) {
			std::cout << iter->elem << " ";
			iter = iter->sig;
		}
		std::cout << '\n';
	}



};

#endif