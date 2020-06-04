
#ifndef smartQueue_h
#define smartQueue_h

#include <iostream>
#include <string>
#include "queue_eda.h"



template <class T>
class smartQueue : public queue<T>{
	using Nodo = typename queue<T>::Nodo;

	//struct Nodo {
	//    Nodo() : sig(nullptr) {}
	//    Nodo(T const& el, Nodo* si = nullptr) : elem(el), sig(si) {}
	//    T elem;
	//    Nodo* sig;
	//};	
public:

	void ampliar(smartQueue<T>& listaNueva, const int& pos) {
        Nodo* nodoActual = this->prim;

        for (int i = 0; i < pos - 1 && nodoActual->sig != nullptr; ++i)
            nodoActual = nodoActual->sig;

        Nodo* tmp = nodoActual->sig;
        if (pos == 0) {
            if (nodoActual->sig == nullptr)
                this->ult = nodoActual;
            listaNueva.ult->sig = nodoActual;
            nodoActual = listaNueva.prim;
            this->prim = nodoActual;
        }
        else {
            nodoActual->sig = listaNueva.prim;
            listaNueva.ult->sig = tmp;
            if (tmp == nullptr)
                this->ult = listaNueva.ult;
        }

        this->nelems = this->nelems + listaNueva.size();
        listaNueva.nelems = 0;
        listaNueva.prim = nullptr;
        listaNueva.ult = nullptr;
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