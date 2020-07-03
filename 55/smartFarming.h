#ifndef carnet_h
#define carnet_h

#include <unordered_map>
#include <stdexcept>
#include <string>
#include <vector>

using plagaS = std::list<std::string>;

class smart_farming {
	const int MAXPUNTOS = 15;
	std::unordered_map<std::string, plagaS> sector;
	std::vector<int> cuantosConPuntos;

	bool find_plaga(std::list<std::string>& list, std::string const& p) {
		bool ok = false;
		auto it = list.begin();							// O(1)
		while (it != list.end() && !ok) {				// Coste de while: O(n); n = num elementos en la lista de dni_s
			if (*it == p)
				ok = true;
			else
				++it;
		}
		return ok;
		//list.erase(it);								// O(1)
	}

public:

	smart_farming() : cuantosConPuntos(MAXPUNTOS + 1, 0) {}

	void alta(std::string const& id) {
		sector[id] = {};
	}

	void datos(std::string const& id, std::string const& p) {
		if (!sector.count(id)) 
			throw std::domain_error("Sector no existente");

		if (find_plaga(sector.at(id), p)) {
			
		}
		else {
			throw std::domain_error("Plaga repetida");
		}
		
	}

	std::vector<std::string> fumigar(std::string const& p) {
		std::vector<std::string> v;
		//Plaga no existente


		return v;
	}

	std::vector<std::string> plagas(std::string const& id) {
		if (!sector.count(id))
			throw std::domain_error("Sector no existente");
		std::vector<std::string> v;


		return v;
	}

};

#endif