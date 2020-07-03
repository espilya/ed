
// ILYA LAPSHIN, A40

// COMENTARIO SOBRE LA SOLUCIÓN
// NO OLVIDES PONER EL COSTE JUSTIFICADO DE CADA OPERACIÓN JUNTO A ELLA

/*

Se usan tres tipos de estructuras de datos:

 - unordered_map <dni, tMatricula> matriculas:
 Se usa para contener todas las matriculas
 tMatricula = { int grupoInd, list<string>::const_iterator it, bool graduado } = un indice del grupo, un iterador a la pos dentro de la lista de un grupo, un bool que se corresponde con el graduado

 - vector<tGrupo> grupos:
 tGrupos = { int grupo, list<string> dni_s } = el grupo, y la lista de alumnos de un grupo

 - set<dni> graduated:
 una lista ordenada de los ya graduados


*/

#ifndef ACADEMIACHINO
#define ACADEMIACHINO

#include <iostream>     
#include <string>
#include <stdexcept>
#include <algorithm>

#include <vector>
#include <set>
#include <list>
#include <unordered_map>

using namespace std;



using grupo = int;
using dni = string;

typedef struct tMatricula {
	int grupoInd;
	list<string>::const_iterator it;
	bool graduado;
}tMatricula;

typedef struct tGrupo {
	int grupo;
	list<string> dni_s;
}tGrupo;

class academia_chino {
	const int NUM_GRUPOS = 6;

	/// <summary>
	/// unordered_map que contiene todas las matriculas, el orden no hace falta
	/// </summary>
	unordered_map <dni, tMatricula> matriculas;

	/// <summary>
	/// vector de grupos. grupos[0] == grupo 1. algo similar como en el problema de carnet2
	/// </summary>
	vector<tGrupo> grupos; // TAM = 6

	/// <summary>
	/// un tipo de datos lineal ordenado usado para contener los graduados
	/// </summary>
	set<dni> graduated;

public:

	// Conste: constructor O(1); Es solo rellenar un array con 6 posiciones. no varia respecto el tamanos de estudiantes.
	academia_chino() {
		for (int i = 1; i < NUM_GRUPOS + 1; i++) {
			grupos.push_back({ i, {} });
		}
	};


	// Coste: O(1); solo operaciones con unordered_map, vector(acceso) y push_front en lista. todas estas operaciones son constantes
	void  nuevo_estudiante(string const& dni, int const& grupo) {
		if (matriculas.count(dni))
			throw domain_error("Estudiante existente");
		if (grupo < 1 || grupo > 7)
			throw domain_error("Grupo incorrecto");

		grupos[grupo - 1].dni_s.push_front(dni);
		matriculas[dni] = { grupo - 1 ,grupos[grupo - 1].dni_s.cbegin(), false };

	}

	// Coste caso peor: O(logN); N = numero de elementos en el tipo de datos lineal ordenado (set); Se da cuando el estudiante se gradua y hay que meterlo en el set
	// Coste mejor: O(1); Se da cuando el estudiante no se gradua y no hay que meterlo en el set
	void  promocionar(string const& dni) {
		if (!matriculas.count(dni))
			throw domain_error("Estudiante no existente");
		if (matriculas.at(dni).graduado)
			throw domain_error("Estudiante ya graduado");

		if (matriculas.at(dni).grupoInd == NUM_GRUPOS - 1) {
			//remove
			 //modificamos datos del estudiante en la matricula
			matriculas.at(dni).grupoInd = -1;
			matriculas.at(dni).graduado = true;
			/*
				Se puede eliminar directamente al alumno del mapa de matriculas al ser matriculado y no usar el bool, con lo cual no gastar memoria
			*/

			// eliminanos de un grupo
			grupos[5].dni_s.erase(matriculas.at(dni).it);
			//matriculas.at(dni).it = grupos[5].dni_s.end();

			// anadimos a lista ordenada de estudiantes graduados. 
			// ------COSTE: O(logN); N = numero de elementos en el tipo de datos lineal ordenado (set)------
			graduated.insert(dni);
		}
		else {
			int nextGrupo = matriculas.at(dni).grupoInd + 1;
			// eliminamos al estudiante de un grupo y lo metemos en otro
			grupos[nextGrupo - 1].dni_s.erase(matriculas.at(dni).it);
			grupos[nextGrupo].dni_s.push_front(dni);
			// cambiamos los datos relacionados con la matricula del estudiante: su iterador en la lista de estudiantes de un grupo, y el indice del grupo
			matriculas.at(dni).it = grupos[nextGrupo].dni_s.cbegin();
			matriculas.at(dni).grupoInd = nextGrupo;
		}
	}

	//Coste: O(1); Es solo acceso a un hashMap y a una casilla de su struct
	int grupo_estudiante(string const& dni) const {
		if (!matriculas.count(dni))
			throw domain_error("Estudiante no existente");
		if (matriculas.at(dni).graduado)
			throw domain_error("Estudiante ya graduado");
		return matriculas.at(dni).grupoInd + 1;
	}


	// Coste mejor: O(1); En caso de que devuelvo el vector por referencia de forma correcta;
	// Coste peor: O(N); N = tam del vector; En caso de que devuelvo el vector por referencia de manera erronea y el compilador hace una copia para devolver el vector. 
	// Pero creo que lo devuelvo bien, con lo cual el coste tiene que ser constante
	const set<dni>& graduados() const {
		return graduated;
	}

	//Coste: O(1); Es solo acceso a un vector y al principio de una lista
	string novato(const int& grupo) {
		//domain error con el mensaje Grupo incorrecto
		//domain error con el mensaje Grupo vacio
		if (grupo < 1 || grupo > 7)
			throw domain_error("Grupo incorrecto");
		if (grupos[grupo - 1].dni_s.empty())
			throw domain_error("Grupo vacio");
		return grupos[grupo - 1].dni_s.front();
	}

};

#endif
