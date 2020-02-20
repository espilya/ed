
#ifndef polinomio_h
#define polinomio_h

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct {
	int coef;
	int exp;
}tMonomio;

class polinomio {

	tMonomio t;
	vector <tMonomio> v;




public:
	polinomio() {}

	polinomio(int c, int e) {
		t.coef = c; t.exp = e;
		v.push_back(t);
	}

	void addMonimio(int c, int e) {
		t.coef = c; t.exp = e;
		//int i = v.size() - 1;
		//while (e < v[i].exp) {
		//	i--;
		//}
		v.push_back(t);

	}

	int evaluar(int valor) {
		int res = 0;
		for (int i = 0; i < v.size(); i++) {
			res += v[i].coef * pow(valor, v[i].exp);
		}
		return res;
	}
};

inline std::istream& operator >> (std::istream& in, polinomio& f) {
	int a, m;
	while (in >> a >> m && (a + m) != 0) {
		f.addMonimio(a, m);
	}
	return in;
}
#endif // conjunto_h