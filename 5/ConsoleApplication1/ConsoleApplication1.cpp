#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "complejos.h"
using namespace std;



//
//3 2 6 1 2 0 0 0
//2
//-2 2




int main() {
	char aux;
	while (cin >> aux) {
		if (aux == 'N') {
			int n, t;
			set<int> v(1);
			cin >> n;
			while (cin >> t && t != -1) {
				v.insert(t);
			}
			set<int> a(1);

			a.insert(v.~set);
			for (int i=1; i < n; i++) {

			}

		}
		else {
			int n;
			string t;
			set<string> v(1);
			cin >> n;
			while (cin >> t && t != "FIN") {
				v.insert(t);
			}

		}

	}
}

