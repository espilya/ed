#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

//#include "alumno.h"

using namespace std;
using nombre = string;
using mapa = map<nombre, int>;
using v = vector<pair<nombre, int>>;

void entrega(mapa& tabla, nombre const& a, string const& nota);
v show(mapa tabla);

int main() {
	mapa tabla;
	int n;
	string nom, res;
	while (cin >> n && n > 0) {
		v mostrar;
		while (n--) {
			cin.ignore();
			getline(cin, nom);
			cin >> res;
			entrega(tabla, (nombre)nom, res);
			mostrar = show(tabla);
		}
		for (auto const& x : mostrar) {
			cout << x.first << ", " << x.second << endl;
		}
		cout << "---" << endl;
		tabla.clear();
	}
	return 0;
}


void entrega(mapa& tabla, nombre const& a, string const& nota) {
	auto it = tabla.find(a);
	if (it == tabla.end())
		tabla.insert(pair<nombre, int>(a, (nota == "CORRECTO" ? 1 : -1))); //si no existe anadimos al dic. y el valor sera 1 o -1 dependiento de la nota
	else
		it->second += (nota == "CORRECTO" ? 1 : -1); //si existe lo encontramos y le sumamos 1 o -1
}

v show(mapa tabla) {
	v resultado;
	for (auto const& x : tabla) {
		if (x.second != 0)
			resultado.push_back(x);
	}
	sort(resultado.begin(), resultado.end());
	return resultado;
}