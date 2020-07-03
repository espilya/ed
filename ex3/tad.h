#ifndef tad_h
#define tad_h

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

using alumno = std::string;
using profesor = std::string;
using puntos = int;



class Tad {
	std::unordered_map<alumno, profesor> matriculas;
	std::unordered_map<profesor, std::map<alumno, puntos>> prof;

public:

	// Coste: 
	Tad() {

	};

	
	void alta(const alumno& a, const profesor& p) {
		
	}

	


};

#endif