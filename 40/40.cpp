#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_set>


//tiene que estar perfecto porque se copio del video donde se explica su implementacion

#define DOMJUDGE

using deporte = std::string;
using alumno = std::string;
using listaAlumnos = std::unordered_set<std::string>;

const std::string fin = "_FIN_";


void solve() {
	std::string str, sport;
	std::map<deporte, listaAlumnos> deportes;
	std::map<alumno, deporte> alum;
	while (std::cin >> str && str != fin) {
		if (isupper(str.at(0))) {
			sport = str;
			deportes.insert({ sport, {} });
		}
		else {
			auto [it, nuevo] = alum.insert({ str, sport });
			if (nuevo) {
				deportes[sport].insert(str);
			}
			else {
				if (it->second != sport) {
					deportes[it->second].erase(str);
				}
			}
		}
	}

	std::vector<std::pair<std::string, int>> resumen;
	for (auto const& e : deportes) {
		resumen.push_back({ e.first, e.second.size() });
	}

	sort(resumen.begin(), resumen.end(), [](std::pair<std::string, int> const& a, std::pair<std::string, int> const& b) {
		return (a.second > b.second) || (a.second == b.second && a.first < b.first); });

	for (auto& pair : resumen)
		std::cout << pair.first << " " << pair.second << '\n';
	std::cout << "---\n";
}


int main() {

	std::string sport;
	while (std::cin) {
		solve();
	}

}