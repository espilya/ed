#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;


typedef struct tSol {
    int act;
    int max;
}tSol;


void resolver(int const &act, int &max) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        if (act > max) max = act;
        resolver(act+1, max);
    }
}


int main() {

    int n; cin >> n;
    //char aux; cin.get(aux);
    for (int i = 0; i < n; i++) {
        int act = 1;
        int max = 0;
        resolver(act, max);
        cout << max+1 << '\n';
    }
}
