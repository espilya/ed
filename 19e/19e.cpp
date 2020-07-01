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
		tree<int> arbol = leerTree(-1);
		//fronteras
		std::vector<int> lista = arbol.fronteras();
		for  (int var : lista){
			cout << var << " ";
		}
		cout << '\n';
	}
}
