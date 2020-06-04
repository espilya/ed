#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "treemap_eda.h"

using namespace std;
using mapa = map<string, int>;
using v = vector<pair<string, int>>;

//void entrega(mapa& tabla, string const& a, string const& nota);
void show(mapa tabla);

int main() {
	int n;
	string nom, res;
	while (cin >> n && n > 0 && cin.ignore()) {
		mapa tabla;
		while (n--) {
			getline(cin, nom);
			getline(cin, res);
			//entrega(tabla);
			if (res == "CORRECTO") {
				++tabla[nom];
			}
			else {
				--tabla[nom];
			}
		}
		show(tabla);
		cout << "---" << endl;
	}

	return 0;
}


//void entrega(mapa& tabla, nombre const& a, string const& nota) {
	//auto it = tabla.find(a);
	//if (it == tabla.end())
	//	tabla.insert(pair<nombre, int>(a, (nota == "CORRECTO" ? 1 : -1))); //si no existe anadimos al dic. y el valor sera 1 o -1 dependiento de la nota
	//else
	//	it->second += (nota == "CORRECTO" ? 1 : -1); //si existe lo encontramos y le sumamos 1 o -1
//}

void show(mapa tabla) {
	v resultado;
	for (auto const& x : tabla) {
		if (x.valor != 0)
			cout << x.clave << ", " << x.valor << endl;
	}
}