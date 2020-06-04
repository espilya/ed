
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)
// ILYA LAPSHIN, (A40)

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
/*
	Insertamos los > al final y dejamos los <= como estan, ya que estan en orden. 
	Coste: 
	- En caso de que toda la lista no tenga el ningun elemento > que el pivote, entonces es solo recorrer la lista: O(K) donde K cantidad de elementos
	- En caso de que toda la lista es > que el pivote, entonces es recorrer la lista + operaciones constantes para insertarlo al final: coste = K + cte -> O(K) donde K cantidad de elementos
	En cualquier caso el coste sera: O(K) donde K cantidad de elementos.
	No hacemos nada mas que recorrer la lista y operaciones constantes que no dependen del tamano de la lista
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <fstream>
#include <string>

using namespace std;

#include "deque_eda.h"

class ListaParticion : public deque<int> {
	// es solo insertar 'insertar', entre 'a' y 'b'
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
	// un cout de la clase. nada especial. recorre todo el deque hasta el nodo fantasma
	void print(std::ostream& o = std::cout) const {
		Nodo* iter = this->fantasma->sig;
		while (iter != this->fantasma) {
			o << iter->elem << " ";
			iter = iter->sig;
		}
		//o << '\n';
	}

	// produce la partición de la lista respecto al privote
	void particion(const int& pivote) {
		Nodo* ordenados = this->fantasma; // el ptr de los <= ya ordenados
		Nodo* primUltOrdenado = nullptr; // el ptr del primer ultimo ya ordenado. usado pasa poder entender cuando es el final y salir
		Nodo* ptr = this->fantasma->sig; // puntero del numero que hay que ordenar en este recorrido del loop
		// seguimos mientras no hemos llegado al fianl y tampoco hemos llegado al primer ultimo ya ordenado
		while (ptr->sig != this->fantasma && ptr != primUltOrdenado) {
			// si el elemento del ptr es <= que el pivote, significa que(que esta en el orden deseado) no tenemos que moverlo sino dejarlo en la misma pos y solo mover los punteros
			if (ptr->elem <= pivote) {
				ordenados = ordenados->sig;
				ptr = ptr->sig;
			}
			// si el elemento es > que el pivote, entonces lo insertamos entre el Nodo anterior al fantasma y el fantasma "(fantasma->ant, INSERTAR_AQUI, fantasma)" 
			// tambien volvemos el puntero ptr al siguiente no_ordenado, para podeder seguir ordenando
			else {
				insertar(this->fantasma->ant, this->fantasma, ptr);
				if (primUltOrdenado == nullptr)
					primUltOrdenado = this->fantasma->ant;
				ptr = ordenados->sig;
			}
		}
	}
};



/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream& o, ListaParticion const& a) {
	a.print(o);
	return o;
}

bool resuelveCaso() {
	int N, pivote;
	cin >> N >> pivote;
	if (!cin)
		return 0;

	ListaParticion lista;
	// leemos la lista de la entrada
	int elem;
	for (int i = 0; i < N; ++i) {
		cin >> elem;
		lista.push_back(elem);
	}


	lista.particion(pivote);

	cout << lista << '\n';

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	// system("PAUSE");
#endif
	return 0;
}
