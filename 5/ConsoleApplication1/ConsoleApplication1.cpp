#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "conjunto.h"

using namespace std;



int main() {

	char ch;
	while (cin >> ch) {
		int n;  cin >> n;
		if (ch == 'N') {
			int i;
			set<int> list;
			while (cin >> i && i != -1) {
				list.insert(i);
			}
			list.calc(n);
			list.show();
		}
		else {
			string i;
			set<string> list;
			while (cin >> i && i != "FIN") {
				list.insert(i);
			}
		list.calc(n);
		list.show();
		}
	}
}

