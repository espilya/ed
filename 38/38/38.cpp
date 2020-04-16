#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;
//para facilitar la lectura y escritura de codigo
using par = pair<string, int>;
using dic = map<string, int>;
using parC = pair<char, string>;
using dicC = map<char, string>;

dic read() {
	dic mapa;
	char aux;
	string str;
	int a;
	do {
		cin >> str >> a;
		mapa.insert(par(str, a));
	} while (cin.get(aux) && aux != '\n');
	return mapa;


}

void solve() {
	dic ini, fin;
	dicC cambios;

	ini = read();//leemos
	fin = read();
	bool hayCambios = false;
	for (par p : ini) {
		auto it = fin.find(p.first);
		if (it == fin.end()) { // no encontrado
			auto it2 = cambios.find('-');
			if (it2 == cambios.end()) {  // no encontrado
				cambios.insert(parC('-', p.first));
				hayCambios = true;
			}
			else // encontrado
				it2->second = it2->second + " " + p.first;
		}
		else { // encontrado
			if (ini[p.first] > fin[p.first] || ini[p.first] < fin[p.first]) {
				auto it2 = cambios.find('*');
				if (it2 == cambios.end()) {  // no encontrado
					cambios.insert(parC('*', p.first));
					hayCambios = true;
				}
				else // encontrado
					it2->second = it2->second + " " + p.first;
			}
		}
	}

	for (parC p : cambios) {
		cout << p.first << " " << p.second << endl;
	}
}


int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		solve();
	}
	cout << "---" << endl;

}
