#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "arbol.h"

using namespace std;





int main() {


	char ch;
	while (cin >> ch) {
		if (ch == 'N') {
			tree<int> arbol = leerTree(-1);
			int res = arbol.menor(INT32_MAX);
			cout << res;
		}
		else if (ch == 'P') {
			tree<string> arbol = leerTree((string)"#");
			string res = arbol.menor("z");
			cout << res;
		}
		cout << '\n';
	}
}
