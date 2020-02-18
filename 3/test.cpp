#include <iostream>
#include <vector>
#include <climits>
#include "complejos.h"
#include <algorithm>


using namespace std;


int main() {

	int numT;


	while (cin >> numT && numT != 0) {
		Pelicula temp;
		vector<Pelicula> pelis;
		for (int i = 0; i < numT; i++) {
			cin >> temp;
			pelis.push_back(temp);
			pelis[i].calcFin();
		}

		sort(pelis.begin(), pelis.end());

		for (int i = 0; i < numT; i++) {
			cout << pelis[i];
		}
		cout << "---\n";
	}
	return 0;
}
