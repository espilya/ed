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
	string str, key;
	int num;

	getline(cin, str);
	string word = "";
	for (auto x : str) {
		if (x == ' ') {
			if (isalpha(word[0]))
				key = word;
			else if (isdigit(word[0]))
				num = stoi(word);
			word = "";
		}
		else {
			word = word + x;
		}
	}
	//cout << word << endl;

	mapa.insert(par(key, num));

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

	for (par p : fin) {
		auto it = ini.find(p.first);
		if (it == ini.end()) { // no encontrado
			auto it2 = cambios.find('+');
			if (it2 == cambios.end()) {  // no encontrado
				cambios.insert(parC('+', p.first));
				hayCambios = true;
			}
			else // encontrado
				it2->second = it2->second + " " + p.first;
		}
	}

	auto it = cambios.find('+');
	if (it != cambios.end())
		cout << it->first << " " << it->second << endl;
	it = cambios.find('-');
	if (it != cambios.end())
		cout << it->first << " " << it->second << endl;
	it = cambios.find('*');
	if (it != cambios.end())
		cout << it->first << " " << it->second << endl;

	if (!hayCambios) {
		cout << "Sin cambios" << endl;
	}
}


int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		solve();
		cout << "---" << endl;
	}


}
