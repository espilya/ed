#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "arbol.h"

using namespace std;





int main() {

	int n; cin >> n;
	//char aux; cin.get(aux);
	for (int i = 0; i < n; i++) {
		tree<char> arbol = leerTree('.');
		//num nodos
		cout << arbol.nodos(arbol) << " ";
		//num hojas
		cout << arbol.hojas(arbol) << " ";
		//altura
		cout << arbol.altura(arbol) << "\n";
	}


}
