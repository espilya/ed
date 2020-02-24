#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "queue_eda.h"

using namespace std;


int main() {
	int t;

	//queue<int> q;
	//q.push(1);
	//q.push(2);
	//q.push(3);
	//q.duplicar();
	//q.toString();

	while (cin) {
		queue<int> q;
		while (cin >> t && t != 0) {
			q.push(t);
		}
		q.duplicar();
		q.toString();
	}

}

