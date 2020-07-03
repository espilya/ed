#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "consultorio.h"

#define DOMJUDGE

bool resuelveCaso() {


	consultorio tad; // Coste: O(1)
	std::string operacion;
	std::string m, p;
	char aux;


	int n; std::cin >> n;
	std::cin >> operacion;
	if (!std::cin) return false;
	n--;
	while (n--) {
		try {
			if (operacion == "nuevoMedico") {
				std::cin >> m;
				tad.nuevoMedico(m);
			}
			else if (operacion == "pideConsulta") {
				int d, h, min;
				std::cin >> p >> m >> d >> h >> aux >> min;
				Fecha  f(d, h, min);
				tad.pideConsulta(p, m, f);
				//std::cout << "Con " << puntos << " puntos hay " << sol << "\n";
			}
			else if (operacion == "siguientePaciente") { // Coste: O(n); n = num elementos en la lista de dni_s en una puntuacion determinada.
				std::cin >> m;
				std::cout << "Siguiente paciente doctor " << m << "\n" << tad.siguientePaciente(m) << "\n";
			}
			else if (operacion == "atiendeConsulta") {
				std::cin >> m;
				tad.atiendeConsulta(m);
				//std::cout << "Puntos de " << dni << ": " << sol << "\n";
			}
			else if (operacion == "listaPacientes") {
				int d;
				std::cin >> m >> d;
				std::vector<tDatosCita> sol = tad.listaPacientes(m, d);
				std::cout << "Doctor " << m << " dia " << d << "\n";
				for (auto e : sol) {
					std::cout << e.paciente << " " << e.fecha.getHora() << ':' << e.fecha.getMin() << "\n";
				}

			}
		}
		catch (const std::exception& e) {
			//std::cout << "ERROR: " << e.what() << "\n";
			std::cout << e.what() << "\n";
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