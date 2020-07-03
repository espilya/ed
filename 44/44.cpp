#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>


using namespace std;

#define DOMJUDGE

//-Caso 1:
//2
//pelicula1 3
//actor1 10 actor2 30 actor3 5
//pelicula2 2
//actor1 10 actor4 30
//3
//pelicula2 pelicula2 pelicula1

//-Como tiene que quedar despues de leer la cantidad de emisiones:
//pelicula1 1
//actor1 10 actor2 30 actor3 5
//pelicula2 2 
//actor1 20 actor4 60

/*

Coste:
-Lectura de datos:
	O(nPel*nAct); nPel = num de peliculas, nAct = num de actores
-Organizacion de datos:
	O(N*p); N = numero de peliculas emitidas, p = numero de actores que tiene cada "N sub[i]" pelicula emitida
-Localizar la pelicula mas vista:
	O(n); n = num de elementos en el unordered_map
-Localizar al actor mas visto:
	O(n); n = num de elementos en el unordered_map

O(nPel*nAct) + O(N*p) + O(n) + O(n)
O(nPel*nAct + N*p + 2n)
nPel = num de peliculas
nAct = num de actores
N = numero de peliculas emitidas
p = numero de actores que tiene cada "N sub[i]" pelicula emitida
n = num de elementos en el unordered_map

*/

void solve() {	
	unordered_map<string, vector<pair<string, int>>> m;
	int n; 
	while (cin >> n && n != 0) {
		int tiempo;
		string pelicula, actor;

		// lectura de datos
		for (int i = 0; i < n; i++) { // O(nPel*nAct); nPel = num de peliculas, nAct = num de actores
			cin >> pelicula;
			vector<pair<string, int>> actores; // O(1)
			int nActores; cin >> nActores; // O(1)
			for (int j = 0; j < nActores; j++) { // O(n); n = num de actores
				cin >> actor; cin >> tiempo; // O(1)
				actores.push_back({ actor , tiempo }); // O(1)

			}
			m[pelicula] = actores; // O(1); es un hashmap, con lo cual se puede decir que es cosntante
		}

		// organizacion de datos
		int N;  cin >> N;
		int maxVistoActor = 0;
		unordered_map<string, int> contador; // contador de cuantas veces se muestra cada pelicula
		unordered_map<string, int> actoresVistos; // aqui se contienen los actores, despues se aumenta el tiempo de cada uno (segun se emite la serie) en las series para despues poder seleccionar al mas visto
		pair<string, int> ultimo; // se usa para guardar la ultima pelicula emitida
		for (int i = 0; i < N; i++) { // O(N*p); N = numero de peliculas emitidas, p = numero de actores que tiene cada "N sub[i]" pelicula emitida
			cin >> pelicula;
			ultimo.first = pelicula;  // O(1)
			contador[pelicula]++;  // O(1) Se puede considerar constante si el factor de carga no es bajo
			if (m.count(pelicula)) {  // O(1)
				for (auto e : m[pelicula]) { // O(p); p = num de actores que tiene una "N sub[i]" pelicula emitida
					actoresVistos[e.first] += e.second; // O(1)
					if (maxVistoActor < actoresVistos[e.first])  // O(1)
						maxVistoActor = actoresVistos[e.first];  // O(1)
				}
			}
		}
		ultimo.second = contador.at(ultimo.first);  // O(1)

		//sacar la pelicula mas vista
		pair<string, int> max; max.second = 0;
		for (auto e : contador) { //  // O(n); n = num de elementos en el unordered_map
			if (e.second > max.second) {
				max.second = e.second;
				max.first = e.first;
			}
		}
		if (max.second == ultimo.second) // O(1)
			max = ultimo; 


		//sacar al actor mas visto
		queue<string> actoresRes;
		for (auto e : actoresVistos) { // O(n); n = num de elementos en el unordered_map
			if (e.second == maxVistoActor) {
				actoresRes.push(e.first);
			}
		}


		//cout
		cout << max.second << " " << max.first << endl << maxVistoActor;
		while (!actoresRes.empty()) {
			cout << ' ' << actoresRes.front();
			actoresRes.pop();
		}
		cout << endl;
	}
}


int main() {

	//int n;
	//while (cin >> n && n!=0) {
		solve();
	//}

}