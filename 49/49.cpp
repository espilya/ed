#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "autoescuela.h"

//#define DOMJUDGE

bool resuelveCaso() {


	autoescuela tad; // Coste: O(1)
	std::string operacion;
	std::string a, p;


	//int n; std::cin >> n;
	std::cin >> operacion;
	if (!std::cin) return false;
	while (operacion != "FIN") {
		try {
			if (operacion == "alta") {
				std::cin >> a >> p;
				tad.alta(a, p);
			}
			else if (operacion == "es_alumno") {
				std::cin >> a >> p;
				if (tad.es_alumno(a, p))
					std::cout << a << " es alumno de " << p << '\n';
				else
					std::cout << a << " no es alumno de " << p << '\n';
			}
			else if (operacion == "puntuacion") { 
				std::cin >> a;
				std::cout << "Puntuacion de " << a  << ": "<< tad.puntuacion(a) << "\n";
			}
			else if (operacion == "actualizar") {
				int puntos;
				std::cin >> a >> puntos;
				tad.actualizar(a, puntos);
			}
			else if (operacion == "examen") {
				int puntos;
				std::cin >> p >> puntos;
				 std::vector<std::string> sol = tad.examen(p, puntos);
				std::cout << "Alumnos de " << p << " a examen:" << "\n";
				for (auto &e : sol) {
					std::cout << e << "\n";
				}
			}
			else if (operacion == "aprobar") {
				std::cin >> a;
				tad.aprobar(a);
			}
		}
		catch (const std::exception& e) {
			std::cout << "ERROR "  << "\n";
			//std::cout << e.what() << "\n";
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
	std::ifstream in("1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

}