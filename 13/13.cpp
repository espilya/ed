#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include "deco.h"

using namespace std;



//Por ejemplo, si X es Anacleto, agente secreto, X0
//serıa Analceto ,agetnes erceto y X00 (el
//mensaje cifrado) serıa Aontaelccreet os e,natge.

int main() {

	string str;
	while (getline(cin, str)) {
		deco<char> lista;
		for (int i = 0; i < str.size(); i++) {
			lista.push_back(str[i]);
		}
			lista.dec();
		lista.toString();
	}


}
