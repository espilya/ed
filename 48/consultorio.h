#ifndef carnet_h
#define carnet_h

#include <unordered_map>
#include <stdexcept>
#include <string>
#include <list> 
#include <iterator> 
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include "fecha.h"







typedef struct tDatosCita {
	Fecha  fecha;
	std::string paciente;
}tDatosCita;


using medico = std::string;
using paciente = std::string;
using datosCita = std::pair<Fecha, std::string>;
using cita = std::map<Fecha, std::string>;


class consultorio {

	std::unordered_map<medico, cita> map;

	// para saber si esta fecha esta ocupada o no. para no tener que recorrer todo el set<tDatosCita> de un determinado medico
	//std::unordered_map<std::pair<Fecha, std::string>, cita> mapFechas;


	void remove_dni_from_list(std::list<std::string>& dni_s, std::string const& dni) {
		bool ok = false;
		auto it = dni_s.begin();
		while (it != dni_s.end() && !ok) {
			if (*it == dni)
				ok = true;
			else
				++it;
		}
		dni_s.erase(it);
	}

public:
	consultorio() {

	};

	void nuevoMedico(medico const& m) {
		if (!map.count(m))
			map[m] = {};
	}

	void pideConsulta(std::string const& p, medico const& m, Fecha const& f) {
		auto itm = map.find(m);
		if (itm == map.cend())
			throw std::domain_error("Medico no existente");
		else {
			auto itf = map[m].find(f);
			if (itf != map[m].cend())
				throw std::domain_error("Fecha ocupada");

			else map[m][f] = p;
		}
	}

	std::string siguientePaciente(std::string const& m) {
		if (!map.count(m))
			throw std::domain_error("Medico no existente");
		if (map.at(m).size() == 0)
			throw std::domain_error("No hay pacientes");
		return	map.at(m).begin()->second;
	}

	void atiendeConsulta(std::string const& m) {
		if (!map.count(m))
			throw std::domain_error("Medico no existente");
		if (map.at(m).size() == 0)
			throw std::domain_error("No hay pacientes");
		map.at(m).erase(map.at(m).begin());
	}

	 std::vector<tDatosCita>  listaPacientes(std::string const& m, int const& d)  {
		if (!map.count(m))
			throw std::domain_error("Medico no existente");
		std::vector<tDatosCita> v;
		for (auto e : map.at(m)) {
			if (e.first.getDia() == d)
				v.push_back({e.first, e.second});
		}
		return v;
	}


};

#endif