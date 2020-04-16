

#include <iostream>
#include <string>
#include "smartQueue.h"
using namespace std;

int main()
{
    int n; 
    smartQueue<int> listaFinal;
    smartQueue<int> elementosInsertar;
    while (cin >> n) {
        int t, pos, m;
        for (int i = 0; i < n; i++){
            cin >> t;
            listaFinal.push(t);
        }
        for (int i = 0; i < m; i++) {
            cin >> t;
            elementosInsertar.push(t);
        }
        listaFinal.ampliar(pos, elementosInsertar);
        listaFinal.toString();
    }
}

