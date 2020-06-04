#ifndef deco_H
#define deco_H

#include "deque_eda.h"

template <class T>
class deco : public deque<T> {
	using Nodo = typename deque<T>::Nodo;

private:

	void intercambiar(Nodo* a, Nodo* b) {
		T ant = a->elem;
		a->elem = b->elem;
		b->elem = ant;
	}

	void pasoDos() {

	}

	bool vocal(Nodo* a) {
		if (a == nullptr)
			return true;
		if (a->elem == 'a')
			return true;
		if (a->elem == 'e')
			return true;
		if (a->elem == 'i')
			return true;
		if (a->elem == 'o')
			return true;
		if (a->elem == 'u')
			return true;
		if (a->elem == 'A')
			return true;
		if (a->elem == 'E')
			return true;
		if (a->elem == 'I')
			return true;
		if (a->elem == 'O')
			return true;
		if (a->elem == 'U')
			return true;
		return false;
	}

	void paso_1() {
		Nodo* iter = this->fantasma->sig;
		Nodo* iterAnt = nullptr;
		while (iter != this->fantasma) {
			if (!vocal(iterAnt) && !vocal(iter)) {
				intercambiar(iterAnt, iter);
				iterAnt = nullptr;
			}
			else {
				iterAnt = iter;
			}
			iter = iter->sig;
		}
	}

	
	//Aontaelccreet os e,natge
	//Analceto ,agetnes erceto
	//Anacleto, agente secreto
	void paso_2() {
		Nodo* iter = this->fantasma->sig;
		Nodo* iterAnt = this->fantasma->ant;
		iter = iter->sig;
		while (iter != iterAnt) {
			intercambiar(iterAnt, iter);
			if (iter->sig != iterAnt)
				intercambiar(iter, iter->sig);
			if (iter->sig == iterAnt)
				break;
			iter = iter->sig;
			iter = iter->sig;
			iterAnt = iterAnt->ant;
		}
	}

public:

	void dec() {
		paso_2();
		//paso_1();
	}


	void toString() {
		Nodo* iter = this->fantasma->sig;
		while (iter != this->fantasma) {
			std::cout << iter->elem;
			iter = iter->sig;
		}
		std::cout << '\n';
	}

};






#endif 
