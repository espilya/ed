#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "list_eda.h"

using namespace std;





int main() {
	int n; 
	int salto;
	while (cin >> n && cin >> salto && n!=0 && salto!=0) {
	list<int> lista;
		bool ok;
		for (int i = 1; i <= n; i++) {
			lista.push_back(i);
		}
		auto it = lista.begin();
	//	if (it != lista.end())
		//	++it;
		while (lista.size() != 1) {
			for (int i = 0; i < salto; i++) {
				it++;	
			}
			it = lista.erase(it);
			if (it == lista.end())
				it = lista.begin();
		}
			cout << *it << "\n";
	}


}
