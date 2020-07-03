#ifndef carnet_h
#define carnet_h

#include <unordered_map>
#include <stdexcept>
#include <string>
#include <list> 
#include <iterator> 
#include <vector>

typedef struct tSol {
	int puntos = 0;
	std::list<std::string> dni_s;
}tSol;

class carnet_puntos {
	const int MAXPUNTOS = 15;
	std::unordered_map<std::string, int> map;
	std::vector<tSol> cuantosConPuntos;

	// O(n); n = num elementos en la lista de dni_s
	void remove_dni_from_list(std::list<std::string>  &dni_s, std::string const& dni) {
		bool ok = false;
		auto it = dni_s.begin();							// O(1)
		while (it != dni_s.end() && !ok) {					// Coste de while: O(n); n = num elementos en la lista de dni_s
			if (*it == dni)
				ok = true;
			else
				++it;
		}
		dni_s.erase(it);									// O(1)
	}

public:

	// constructor O(1) 
	carnet_puntos() { 
		tSol t; t.puntos = 0;
		 for (int i = 0; i < MAXPUNTOS + 1; i++) {
			 cuantosConPuntos.push_back(t);
		 }
	};

	// Coste: O(1) 
	void nuevo(const std::string& dni) {
		tSol t = cuantosConPuntos[MAXPUNTOS];
		if (map.count(dni) == 1)
			throw std::domain_error("Conductor duplicado");
		map[dni] = MAXPUNTOS;									// O(1)
		t.dni_s.push_back(dni);
		t.puntos++;
		cuantosConPuntos[MAXPUNTOS] = t;						// O(1)
	}

	// --Coste caso peor: O(n); n = num elementos en la lista de dni_s en una puntuacion determinada. --Caso caso mejor: O(1)
	void quitar(const std::string& dni, const int& puntos) {
		if (map.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");
		if (map.at(dni) == 0)									// Coste de if: O(1)
			map[dni] = 0;
		else if (map.at(dni) < puntos) {						// Coste de else if: O(n); n = num elementos en la lista de dni_s
			tSol t = cuantosConPuntos[map[dni]];				// O(1)
			t.puntos--;											
			remove_dni_from_list(t.dni_s, dni);					// O(n); n = num elementos en la lista de dni_s
			cuantosConPuntos[map[dni]] = { t.puntos, t.dni_s};	// O(1)

			map[dni] = 0;										// O(1)
			t = cuantosConPuntos[0];							// O(1)
			t.puntos++;											
			t.dni_s.push_back(dni);								
			cuantosConPuntos[0] = { t.puntos, t.dni_s };		// O(1)
		}
		else {													// Coste de else: O(n); n = num elementos en la lista de dni_s
			tSol t = cuantosConPuntos[map[dni]];				// O(1)
			t.puntos--;											
			remove_dni_from_list(t.dni_s, dni);					// O(n); n = num elementos en la lista de dni_s
			cuantosConPuntos[map[dni]] = { t.puntos, t.dni_s };	// O(1)

			map[dni] -= puntos;									// O(1)
			t = cuantosConPuntos[map[dni]];						// O(1)
			t.puntos++;											
			t.dni_s.push_back(dni);								
			cuantosConPuntos[map[dni]] = { t.puntos, t.dni_s };	// O(1)
		}
	}

	// --Coste caso peor: O(n); n = num elementos en la lista de dni_s en una puntuacion determinada. --Caso caso mejor: O(1)
	void recuperar(const std::string& dni, const int& puntos) {
		if (map.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");
		if (map.at(dni) == 15)									// Coste de if: O(1)
			map[dni] = 15;
		else {													// Coste de else: O(n); n = num elementos en la lista de dni_s
			tSol t = cuantosConPuntos[map[dni]];				// O(1)
			t.puntos--;
			remove_dni_from_list(t.dni_s, dni);					// O(n); n = num elementos en la lista de dni_s
			cuantosConPuntos[map[dni]] = { t.puntos, t.dni_s }; // O(1)

			map[dni] += puntos;									// O(1)
			t = cuantosConPuntos[map[dni]];						// O(1)
			t.puntos++;
			t.dni_s.push_back(dni);
			cuantosConPuntos[map[dni]] = { t.puntos, t.dni_s }; // O(1)
		}
	}

	// --Coste caso peor: O(n); n = num elementos en la lista de dni_s en una puntuacion determinada. --Caso caso mejor: O(1)
	std::vector<std::string> lista_por_puntos(const int&  puntos) {
		if (puntos > 15 || puntos < 0)
			throw std::domain_error("Puntos no validos");
		std::vector<std::string> v;
		tSol t = cuantosConPuntos[puntos];						// O(1)
		auto it = t.dni_s.rbegin();								// O(1)
		while (it != t.dni_s.rend()) {							// Coste de while: O(n); n = num elementos en la lista de dni_s
			v.push_back(*it);
			++it;
		}
		return v;
	}

	// Coste: O(1)
	int consultar(const std::string& dni) const { 
		if (map.count(dni) == 0)
			throw std::domain_error("Conductor inexistente");
		return map.at(dni);
	}

	// Coste: O(1)
	int cuantos_con_puntos(int puntos) const {
		if (puntos < 0 || puntos > MAXPUNTOS)
			throw std::domain_error("Puntos no validos");

		return cuantosConPuntos[puntos].puntos;
	}
};

#endif