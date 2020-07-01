#include <iostream>
#include <fstream>
#include <string>
#include "treemap_eda.h"
#include "hashmap_eda.h"

// En el caso peor es lineal, en el caso mejor es constante.

#define DOMJUDGE

struct cmpByStringLength {
	bool operator()(const std::string& a, const std::string& b) const {
		return a.length() < b.length();
	}
};

using nombreEquipo = std::string;
using nombreProblema = std::string;
using estadoDelEnvio = bool;
using envio = std::pair<int, estadoDelEnvio>;
using problemas = unordered_map<nombreProblema, envio>;


bool resuelveCaso() {
	map<nombreEquipo, problemas> equipos;
	std::string nombreEquipo; std::cin >> nombreEquipo;

	while (nombreEquipo != "FIN") {
		std::string nombreProblema; std::cin >> nombreProblema;
		int tiempo; std::cin >> tiempo;
		std::string resultado; std::cin >> resultado;

		if (!equipos[nombreEquipo][nombreProblema].second) {
			if (resultado == "AC") {
				std::pair<int, estadoDelEnvio> t = equipos[nombreEquipo][nombreProblema];
				t.first += tiempo;
				t.second = true;
				equipos[nombreEquipo][nombreProblema] = t;
			}
			else {
				std::pair<int, estadoDelEnvio> t = equipos[nombreEquipo][nombreProblema];
				t.first += 20;
				t.second = false;
				equipos[nombreEquipo][nombreProblema] = t;
			}
		}
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


	std::cout << "---" << std::endl;

	return true;
}

int main() {

	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int n; std::cin >> n;
	while (n--) {
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

}