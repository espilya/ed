

#ifndef complejos_h
#define complejos_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <string>


 
using namespace std;

template <class T>
class complejos {

	T real;
	T imaginario;
	

public:
	complejos() : inicio(), duracion(), fin(), nombre(""){};
	complejos(Tiempo ini, Tiempo d, Tiempo f, string nmb) : inicio(ini), duracion(d), fin(f), nombre(nmb) {};

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
		com.real = real*f.real - imaginario * f.imaginario;
		com.imaginario = real * f.imaginario - f.real * imaginario;
		return com;
	}

	modulo (complejos const& f) const {
		//mod(a+bi) = sqrt(a2 + b2)
		complejos com;

		return com;
	}

};


inline std::ostream& operator << (std::ostream& out, complejos const& f) {
	//out << f.getFin() << "" << f.getNombre() << '\n';
	return out;
}

template <class T>
inline std::istream& operator >> (std::istream& in, complejos& f) {
	Tiempo inicio, duracion, fin;
	string nombre;
	in >> inicio >> duracion;
	getline(in, nombre);
	f = Pelicula(inicio, duracion, fin, nombre);
	return in;
}


#endif // !class_h