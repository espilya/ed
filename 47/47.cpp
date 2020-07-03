#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "carnet.h"

#define DOMJUDGE

bool resuelveCaso() {


	carnet_puntos carnet; // Coste: O(1)
	std::string operacion, dni;
	int puntos;

	std::cin >> operacion;
	if (!std::cin) return false;

	while (operacion != "FIN") {
		try {
			if (operacion == "nuevo") { // Coste: O(1)
				std::cin >> dni;
				carnet.nuevo(dni);
			}
			else if (operacion == "cuantos_con_puntos") { // Coste: O(1)
				std::cin >> puntos;
				int sol = carnet.cuantos_con_puntos(puntos);
				std::cout << "Con " << puntos << " puntos hay " << sol << "\n";
			}
			else if (operacion == "quitar") { // Coste: O(n); n = num elementos en la lista de dni_s en una puntuacion determinada.
				std::cin >> dni >> puntos;
				carnet.quitar(dni, puntos);
			}
			else if (operacion == "consultar") { // Coste: O(1)
				std::cin >> dni;
				int sol = carnet.consultar(dni);
				std::cout << "Puntos de " << dni << ": " << sol << "\n";
			}
			else if (operacion == "lista_por_puntos") { // Coste: O(n); n = num elementos en la lista de dni_s en una puntuacion determinada.
				std::cin >> puntos;
				std::vector<std::string> v = carnet.lista_por_puntos(puntos);
				std::cout << "Con " << puntos << " puntos hay ";
				for (auto e : v) {
					std::cout << e << " ";
				}
				std::cout <<  "\n";
			}
			else if (operacion == "recuperar") { // OCoste: (n); n = num elementos en la lista de dni_s en una puntuacion determinada.
				std::cin >> dni >> puntos;
				carnet.recuperar(dni, puntos);
			}
		}
		catch (const std::exception &e) {
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