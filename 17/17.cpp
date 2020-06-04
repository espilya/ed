#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <fstream>
#include <string>
#include <ctype.h>
#include "fat.h"
using namespace std;





int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a,t; cin >> a;
		fat<int> lista1;
		fat<int> lista2;
		while (a--) {
			cin >> t;
			lista1.push_back(t);
		}
		cin >> a;
		while (a--) {
			cin >> t;
			lista2.push_back(t);
		}
		lista1.ampliar(lista2);
		lista1.show();
	}

}
