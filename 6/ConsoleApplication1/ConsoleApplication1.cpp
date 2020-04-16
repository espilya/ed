#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <stack>

using namespace std;



//
//3 2 6 1 2 0 0 0
//2
//-2 2



const string todos = "[{(}])";

const string abierto = "[{(";


int main() {
	string str;
	while (getline(cin, str)) {
		bool ok = true;
		stack<char> pila;
		int i = 0;
		while (ok && i < str.size()) {
			char a = str[i];
			if (todos.find(a) != string::npos) {
				if (abierto.find(a) != string::npos) {
					pila.push(a);
				}
				else {
					if (pila.empty())
						ok = false;
					else {
						char b = pila.top();
						pila.pop();
						switch (a) {
						case ']':
							ok = (b == '[');
							break;
						case '}':
							ok = (b == '{');
							break;
						case ')':
							ok = (b == '(');
							break;
						}
					}

				}
			}
			i++;
		}
		ok = ok && pila.empty();
		cout << (ok ? "SI" : "NO") << endl;
	}

}

