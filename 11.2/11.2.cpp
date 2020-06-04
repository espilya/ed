
#include <iostream>
#include "orderQueue.h"
using namespace std;
int main(){

	int i; cin >> i;
	while (i--) {
        orderQueue<int> lista1, lista2;
        int tmp;
        std::cin >> tmp;
        while (tmp != 0) {
            lista1.push_back(tmp);
            std::cin >> tmp;
        }
        std::cin >> tmp;
        while (tmp != 0) {
            lista2.push_back(tmp);
            std::cin >> tmp;
        }
        lista1.merge(lista2);

        lista1.toString();


	}

}

