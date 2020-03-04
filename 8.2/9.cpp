#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "deque_eda.h"

using namespace std;


int main() {
	int t;




	while (cin) {
		deque<int> q;
		while (cin >> t && t != 0) {
			q.push_back(t);
		}
		q.duplicar();
		q.toString();
		/* q.~deque(); sale excepcion :\   */
	}
	// y aqui no sale
	//deque<int> q;
	//q.push_back(5);
	//q.push_back(4);
	//q.push_back(1);
	//q.push_back(8);
	//q.duplicar();
	//q.toString();
	//q.~deque();
}

