#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
/*
Ilya Lapshin



El coste es constante O(1)

*/

using nombreDelJuego = std::string;
using numeroDeVeces = int;
using ultimaPos = int;

using pair = std::pair<numeroDeVeces, ultimaPos>;

int main() {

	int n, m, t; 
	while (std::cin >> n) {
		std::unordered_map < nombreDelJuego, std::vector<int> > tabla;
		//std::pair<numeroDeVeces, ultimaPos> par;
		std::string str;
		for (int i = 0; i < n; ++i) {
			std::cin >> str;
			tabla[str].push_back(i);
			//se rellena el vector value de un key
		}
		std::cin >> m;
		for (int i = 0; i < m; ++i) {
			std::cin >> t;
			std::string str;
			std::cin >> str;
			auto iterator = tabla.find(str);
			if (iterator == tabla.cend()) {
				//si el key n esta
				std::cout << "NO JUEGA" << std::endl;
			}
			else if (tabla.at(str).size() < t) {
				//si el value es menor
				std::cout << "NO JUEGA" << std::endl;
			}
			else {
				//si  el value es igual
				std::cout << tabla.at(str)[t-1] + 1 << std::endl;
			}
		}
		std::cout << "---" << std::endl;
	}
}
	
