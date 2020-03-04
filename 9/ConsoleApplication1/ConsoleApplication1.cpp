#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "queue_eda.h"

using namespace std;


int main() {
	while (cin) {
		queue<int> q;
		int t;
		while (cin >> t && t != 0) {
			q.push(t);
		}
		q.invertir();
		q.toString();

	}
}


