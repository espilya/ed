
#ifndef complejos_h
#define complejos_h


template <typename T1, typename T2>
class complejos {
	T1 _primero; 
	T2 _segundo;


public:
	// Constructor

	complejos(T1 a, T2 b) : _primero(a), _segundo(b) { }
	// Observadoras
	T1 primero() const { return _primero; }
	T2 segundo() const { return _segundo; }
};


#endif // conjunto_h