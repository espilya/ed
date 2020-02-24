

#ifndef complejos_h
#define complejos_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <cmath>
#include <string>



using namespace std;

template <class T>
class complejos {

	T real;
	T imaginario;

	complejos operator + (complejos const& f) const {
		// com==NEW
		// this==a+bi
		// f==c+di
		//(a+bi) + (c+di) = (a+c) + (b+d)i
		complejos com;
		com.real = real + f.real;
		com.imaginario = imaginario + f.imaginario;
		return com;
	}

	complejos operator * (complejos const& f) const {
		//(a+bi) * (c+di) = (a*c-b*d) + (a*d+c*b)i
		complejos com;
		com.real = real * f.real - imaginario * f.imaginario;
		com.imaginario = real * f.imaginario - f.real * imaginario;
		return com;
	}

	double modulo(complejos const& f) const {
		return sqrt(real * real + imaginario * imaginario);;
	}



public:
	complejos() : inicio(), duracion(), fin(), nombre("") {};
	complejos(Tiempo ini, Tiempo d, Tiempo f, string nmb) : inicio(ini), duracion(d), fin(f), nombre(nmb) {};


	bool evaluar(int iter) {
		int i = 0;
		double a = 0;

		//z0 = 0
		//zn = z(n−1)^2 + c
		while (i < iter && a < 2) {
			a = a*a + c
		}
	}

};



#endif // !class_h