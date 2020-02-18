#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "polinomio.h"
using namespace std;



//
//3 2 6 1 2 0 0 0
//2
//- 2 2


int main() {
	int c, e;

	polinomio p;
	while (cin >> c >> e && (c + e) != 0) {
		p.addMonimio(c, e);
	}
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		cout << p.evaluar(t) << ' ';
	}

}

