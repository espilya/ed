
#ifndef polinomio_h
#define polinomio_h

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef struct {
	int coef;
	int exp;
}tMonomio;

class polinomio {
	tMonomio t;
	vector <tMonomio> v;
public:
	polinomio() {	}

	polinomio(int c, int e) {
		t.coef = c; t.exp = e;
		v.push_back(t);
	}

	void addMonomio(int c, int e) {
		t.coef = c; t.exp = e;
		//int i = v.size() - 1;
		//while (e < v[i].exp) {
		//	i--;
		//}
		v.push_back(t);

	}

	int evaluar(const int&  valor) {
		int sol = 0;
		for (int i = 0; i < v.size(); i++)
			sol += v.at(i).coef * pow(valor, v.at(i).exp);

		return sol;
	}
	
	
};	

inline std::istream& operator >> (std::istream& in, polinomio& f) {
	int a, m;
	while (in >> a >> m && (a + m) != 0) {
		f.addMonomio(a, m);
	}
	return in;
}
#endif // conjunto_h