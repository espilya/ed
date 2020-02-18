#ifndef Tiempo_h
#define Tiempo_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <stdio.h>
#include <iomanip>



using namespace std;

class Tiempo {
	int hh, mm, ss;

public:
	Tiempo() : hh(0), mm(0), ss(0) {};
	Tiempo(int h, int m, int s) : hh(h), mm(m), ss(s) {
		if(hh >= 24 || hh < 0 || mm < 0 || mm >= 60 || ss >= 60 || ss < 0)
			throw invalid_argument("ERROR");
	};

	int getHH() const { return hh; };
	int getMM() const { return mm; };
	int getSS() const { return ss; };


	Tiempo operator + (Tiempo const& f) const {
		Tiempo suma;
		int add;

		suma.ss = ss + f.ss;

		add = 0;
		if (suma.ss > 59) {
			add = 1;
			suma.ss = suma.ss - 60;
		}
		suma.mm = mm + f.mm + add;

		add = 0;
		if (suma.mm > 59) {
			add = 1;
			suma.mm = suma.mm - 60;
		}
		suma.hh = hh + f.hh + add;

		//if (suma.hh > 24)
		//	throw invalid_argument("ERROR de suma");
		return suma;
	}

	bool operator< (Tiempo const& t) const {
		if (hh < t.hh) return true;
		else if (hh > t.hh) return false;
		else if (mm < t.mm) return true;
		else if (mm > t.mm) return false;
		else if (ss < t.ss) return true;
		else return false;
	}
	bool operator == (Tiempo const& f) const {
		return hh == f.hh && mm == f.mm && ss == f.ss;
	}
	bool operator <= (Tiempo const& f) const {
		return *this < f || *this == f;
	}
	bool operator > (Tiempo const& f) const {
		return !(*this <= f);
	}
	bool operator >= (Tiempo const& f) const {
		return !(*this < f);
	}
};

inline std::ostream& operator << (std::ostream& out, Tiempo const& f) {

	out << setw(2) << setfill('0') << f.getHH() << ':';
	out << setw(2) << setfill('0') << f.getMM() << ':';
	out << setw(2) << setfill('0') << f.getSS();
	return out;
}
inline std::istream& operator >> (std::istream& in, Tiempo& f) {
	int h, m, s;
	char aux;
	in >> h >> aux >> m >> aux >> s;
	f = Tiempo(h, m, s);
	return in;
}


#endif // !class_h