#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;



//
//3 2 6 1 2 0 0 0
//2
//-2 2




int main() {
	string str;
	while (getline(cin, str)) {
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '[')
				a++;
			else if (str[i] == ']')
				a--;
			else if (str[i] == '{')
				b++;
			else if(str[i] == '}')
				b--;
			else if(str[i] == '(')
				c++;
			else if (str[i] == ')')
				c--;
		}
		cout << ((a == 0 && b == 0 && c == 0) ? "SI" : "NO") << endl;
	}
}

