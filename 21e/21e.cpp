#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "arbol.h"

using namespace std;



void solve(tree<int> arbol) {
	int i;
	auto iter = arbol.begin();
	while (iter != arbol.end()) {
		cout << *iter << iter() << ":\n";
		cin >> i;
	}
}



int main() {


	int  ch; cin >> ch;
	while (ch--) {
		tree<int> arbol = leerTree(-1);
		//tDiam d = arbol.diam();
		solve(arbol);
		cout << '\n';
	}
}
