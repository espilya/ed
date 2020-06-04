#ifndef tad_h
#define tad_h

#include <unordered_map>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>
#include <list>

//ILYA LAPSHIN
//sin terminar

class ParqueNatural {
	using especie = std::string;
	using ecosistema = std::string;
	int plantas;
	std::unordered_map<ecosistema, std::map<especie, int>> ecosistemas;

public:

	//ParqueNatural() {};



	void crea() {

	}

	void an_ecosistema(const ecosistema& id) {
		if (ecosistemas.count(id) == 1)
			throw std::domain_error("EEcosistemaDuplicado");
		ecosistemas.insert({ id, NULL });
	}

	void an_ejempalres(const ecosistema& eco, const especie& esp, const int& n) {
		if (ecosistemas.count(eco) == 1)
			throw std::domain_error("EEcosistemaNoExiste");
		ecosistemas[eco][esp] += n;
	}


	std::vector<especie> lista_especies_ecosistema(const ecosistema& eco, const int& n) {
		std::vector<especie> lista;
		//std::map<especie, int> ecosistemas[eco]

		//for (int i = 0; i < n; i++) {
		//	auto it = 
			//if(lista.)
			//it->second.;
		//}
		return lista;
	}

	int numero_de_ejemplares_en_ecosistema(const ecosistema& eco, const especie& esp) {
		if (ecosistemas.count(eco) == 0)
			throw std::domain_error("EEcosistemaNoExiste");
		return ecosistemas[eco].count(esp) == 0;
	}


	std::vector<especie> lista_especies_parque() {
		std::vector<especie> lista;
		for (auto it = ecosistemas.begin(); it != ecosistemas.end(); it++) {
			//if(lista.)
			//it->second.;
		}
		return lista;
	}



	int numero_de_ejemplares_en_parque(const especie& esp) {
		int count = 0;
		for (auto it = ecosistemas.begin(); it != ecosistemas.end(); it++)
			count += it->second.count(esp);
		return count;
	}


};

#endif