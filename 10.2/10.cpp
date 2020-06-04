

#include <iostream>
#include <string>
#include "smartQueue.h"
using namespace std;

int main()
{
    int n; 
    while (cin >> n) {
    smartQueue<int> listaFinal;
    smartQueue<int> elementosInsertar;
        int t, pos, m;
        for (int i = 0; i < n; i++){
            cin >> t;
            listaFinal.push_back(t);
        }
        cin >> m >> pos;
        for (int i = 0; i < m; i++) {
            cin >> t;
            elementosInsertar.push_back(t);
        }
        listaFinal.ampliar( elementosInsertar, pos);
        listaFinal.toString();
    }
}

