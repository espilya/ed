#ifndef carnet_h
#define carnet_h

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <ctype.h>
#include <string>

#include <iterator> 
#include <list> 
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <map>


typedef struct tSol {
	int puntos = 0;
	std::list<std::string> dni_s;
}tSol;

using sector = std::string;
using plaga = std::string;
using puntos = int;



class SmartFarm {
	const int MAXPUNTOS = 15;
	std::unordered_map<alumno, profesor> matriculas;
	std::unordered_map<profesor, std::map<alumno, puntos>> prof;

public:

	// constructor O(1) 
	SmartFarm() {

	};

	void alta(const sector& id, const int& n) {
		
	}
	 
	void datos(const sector& id, const plaga& p, const int& n) {
		//Sector no existente
	}

	void fumigar() {

	}

	void plagas(const sector& id) {

	}
	


};

#endif