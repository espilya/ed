
// NOMBRE Y APELLIDOS (USUARIO DEL JUEZ)
// ILYA LAPSHIN, A40

/*
Recorre el arbol de forma recursivade por el orden de IDZ.
La funcion devuelve el valor del nodo actual (en caso de si es hoja), o el valor de la suma de todos los nodos que pertenecen a el (estan debajo de el) mas el mismo.
En un caso base y despues de ver los dos nodos, se comprueba si 


Coste:
        
        / c0                            si a.empty() || (nodo.left().empty() && nodo.right().empty())
T(n) = {
        \ T(nI) + T(nD) + c1            si !a.empty()

Notacion:
nI = nodo Izq, nD = nodo Der, c0 = constante, c1 = constante

El coste es constante, se recorre el arbol completo, con lo cual el coste es lineal O(n), donde n es el numero de elementos de arbol.
El algoritmo trata una vez cada nodo del arbol y el coste de tratar cada nodo, es constante, por lo tanto el coste del algoritmo es lineal en el numero de nodos del arbol.
En el caso base y despues de ver los dos nodos, se comprueba si es un nodo acumulador.

*/

#define DOMJUDGE

#include <iostream>                                             
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"




int acumuladores(bintree<int> nodo, int &ctd) {

    //CASOS BASE
    if (nodo.empty()) // si es vacio
        return 0;
    else if (nodo.left().empty() && nodo.right().empty()) { // si sus hijos son vacios
        if(nodo.root() == 0){ 
            ctd++; 
        }
        return nodo.root();
    }
    
    //CASOS RECURSIVOS
    else {
       // int der, izq; 
       // izq = acumuladores(nodo.left(), ctd); // nodo derecho
       // der = acumuladores(nodo.right(), ctd); // nodo izquierdo
       // int suma = izq + der;
        int suma = acumuladores(nodo.left(), ctd) + acumuladores(nodo.right(), ctd); // suma de nodo izq y nodo der
        if (suma == nodo.root()) {
            ctd++;
        }
        return  suma + nodo.root();
    }
}


void resuelveCaso() {
    int ctd = 0;
    auto arbol = leerArbol(-1);
    acumuladores(arbol, ctd);
    cout << ctd << '\n';
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
