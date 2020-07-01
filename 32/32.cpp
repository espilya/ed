#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "set_eda.h"

using namespace std;


typedef struct box {
	int gen;
}box;





void resolver() {

}


int main() {

	int n, t;

	while (cin >> n && n != 0) {
		set<int> tree;
		for (int i = 0; i < n; i++) {
			cin >> t;
			tree.insert(t);
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> t;
			pair<bool, int>	p = tree.lower_bound(t);
			cout << (p.first ? to_string(p.second) : "NO HAY");
			cout << '\n';
		}
		cout << '\n';
	}
}
