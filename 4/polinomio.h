#pragma once


#include <vector>
#include <iostream>
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

	void addMonimio(int c, int e) {
		t.coef = c; t.exp = e;
		v.push_back(t);
	}	

	int evaluar(int valor) {
		int res =0;
		for (int i = 0; i < v.size(); i++){
			res += v[i].coef * pow(valor, v[i].exp);
		}
		return res;
	}
};


