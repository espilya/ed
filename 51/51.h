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

using alumno = std::string;
using profesor = std::string;
using puntos = int;
using puntos = int;


class Tad {
	const int MAXPUNTOS = 15;
	std::unordered_map<alumno, profesor> matriculas;
	std::unordered_map<profesor, std::map<alumno, puntos>> prof;

public:

	// constructor O(1) 
	Tad() {

	};

	// O(log(n)); n = num de estudiantes que tiene un profesor determinado
	void alta(const alumno& a, const profesor& p) {
		if (matriculas.count(a)) {
			profesor profAntiguo = matriculas[a];
			prof[p][a] = prof.at(profAntiguo).at(a); // O(log(n)); n = num de estudiantes que tiene un profesor determinado
			prof[profAntiguo].erase(a); // O(1)
			matriculas[a] = p; // O(1)
		}
		else {
			prof[p][a] = 0; // O(log(n)); n = num de estudiantes que tiene un profesor determinado
			matriculas[a] = p;
		}
	}

	// O(1)
	bool es_alumno(const alumno& a, const profesor& p) {
		return (matriculas.count(a) && matriculas.at(a) == p);
	}

	// O(log(n)); n = num de estudiantes que tiene un profesor determinado
	int puntuacion(alumno const& a) {
		if (matriculas.count(a)) {
			return prof.at(matriculas.at(a)).at(a);
		}
		else {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
	}

	// O(log(n)); n = num de estudiantes que tiene un profesor determinado
	void actualizar(const alumno& a, const int& n) {
		if (matriculas.count(a)) {
			prof[matriculas.at(a)][a] += n;
		}
		else {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
	}

	// O(log(n)); n = num de estudiantes que tiene un profesor determinado
	std::vector<std::string>  examen(const profesor& p, const int& n) {
		std::vector<std::string> v;
		if (prof.count(p)) {
			for (auto e : prof.at(p)) {
				if (e.second >= n)
					v.push_back(e.first);
			}
		}
		return v;
	}


	// O(log(n)); n = num de estudiantes que tiene un profesor determinado
	void aprobar(const alumno& a) {
		if (matriculas.count(a)) {
			prof[matriculas.at(a)].erase(a);
			matriculas.erase(a);
		}
		else {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
	}


};

#endif