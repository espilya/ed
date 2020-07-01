#include <iostream>
#include <fstream>
#include <string>
#include "hashmap_eda.h"

// En el caso peor es lineal, en el caso mejor es constante.

#define DOMJUDGE

bool resuelveCaso() {
	unordered_map<int, std::string> m;
	int tam; std::cin >> tam;
	if (tam == 0) return false;
	
	while (tam--) {
		int clave, valor = 0;
		std::cin >> clave;
		m[clave] = valor;
	}
	
	auto it = m.begin();
	while (it != m.end()) {
		auto act = *it;
		if (act.clave % 2 == 0) {
			it = m.erase(it); 
		}
		else {
			++it;
		}
	}

	 it = m.begin();
	bool ok = true;
	while (it != m.end() && ok) {
		auto act = *it;
		if (act.clave % 2 == 0) 
			ok = false;
		else 
			++it;
	}

	std::cout << (ok ? "TODO BIEN" : "TODO MAL") << std::endl;

	return true;
}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

}