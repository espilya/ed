#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "deque_eda.h"

using namespace std;


int main() {
	while (cin) {
		deque<int> q;
		int t;
		while (cin >> t && t != 0) {
			q.push_back(t);
		}
		q.invertir();
		q.toString();

	}
}


