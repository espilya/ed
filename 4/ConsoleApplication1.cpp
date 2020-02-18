#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "polinomio.h"
using namespace std;




int main(){
	int c, e;
	while (true){
		polinomio p;
		while (cin >> c >> e && (c + e) != 0) {
			p.addMonimio(c, e);
		}
		int n, t; 
		cin >> n;
		for (int i = 0; i++; i < n) {
			cin >> t;
			cout << p.evaluar(t);
		}
	}


}

