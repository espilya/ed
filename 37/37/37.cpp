#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <limits.h>

using serie = int;

int main() {

	int n, m, t; std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::map < serie,  int > tabla;
		std::cin >> m;
		int counter = 0;
		int max = 0;
		int start = 1;
		for (int j = 0; j < m; ++j) {
			std::cin >> t;
			if (tabla[t] >= start) {
				start = tabla[t] + 1;
				counter = j - tabla[t] +1;
			}
			else {
				++counter;
				if (max < counter)
					max = counter;
			}
			tabla[t] = j+1;
		}
		std::cout << max << std::endl;
	}
}
