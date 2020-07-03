#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "smartFarming.h"

#define DOMJUDGE

bool resuelveCaso() {


	smart_farming farm;
	std::string operacion, id, plaga;


	std::cin >> operacion;
	if (!std::cin) return false;

	while (operacion != "FIN") {
		try {
			if (operacion == "alta") { // Coste: O(1)
				std::cin >> id;
				farm.alta(id);
			}
			else if (operacion == "datos") { // Coste: O(1)
				std::cin >> id >> plaga;
				farm.datos(id, plaga);
			}
			else if (operacion == "fumigar") { // Coste: O(n); n = num elementos en la lista de id_s en una puntuacion determinada.
				std::cin >> id;
				std::vector<std::string> sol = farm.fumigar(id);
				std::cout << "Fumigar la plaga " << id << " en los sectores :";
				for (auto e : sol) {
					std::cout << e << " ";
				}
				std::cout << "\n";
			}
			else if (operacion == "plagas") { // Coste: O(1)
				std::cin >> id;
				std::vector<std::string> sol = farm.plagas(id);
				std::cout << "Plagas del sector " << id << " : ";
				for (auto e : sol) {
					std::cout << e << " ";
				}
				std::cout << "\n";
			}
			//else if (operacion == "lista_por_plaga") { // Coste: O(n); n = num elementos en la lista de id_s en una puntuacion determinada.
			//	std::cin >> plaga;
			//	std::vector<std::string> v = farm.lista_por_plaga(plaga);
			//	std::cout << "Con " << plaga << " plaga hay ";
			//	for (auto e : v) {
			//		std::cout << e << " ";
			//	}
			//	std::cout << "\n";
			//}
			//else if (operacion == "recuperar") { // OCoste: (n); n = num elementos en la lista de id_s en una puntuacion determinada.
			//	std::cin >> id >> plaga;
			//	farm.recuperar(id, plaga);
			//}
		}
		catch (const std::exception& e) {
			std::cout << "ERROR: " << e.what() << "\n";
		}
		std::cin >> operacion;
	}

	std::cout << "---\n";

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