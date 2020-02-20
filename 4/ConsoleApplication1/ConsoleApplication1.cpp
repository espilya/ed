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
//-2 2


int main() {
	while (1) {
		polinomio p;
		cin >> p;

		int n, t;
		cin >> n;
		vector <int> v2;
		for (int i = 0; i < n; i++) {
			cin >> t;
			v2.push_back(t);
		}
		for (int i = 0; i < n; i++) {
			cout << p.evaluar(v2[i]) << " ";
		}
		cout << endl;
	}
}

