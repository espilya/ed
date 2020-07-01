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

void solve() {	
	unordered_map<string, vector<pair<string, int>>> m;
	int n; 
	while (cin >> n && n != 0) {
		int tiempo;
		string pelicula, actor;

		for (int i = 0; i < n; i++) {
			cin >> pelicula;
			vector<pair<string, int>> actores;
			int nActores; cin >> nActores;
			for (int j = 0; j < nActores; j++) {
				cin >> actor; cin >> tiempo;
				actores.push_back({ actor , tiempo });

			}
			m[pelicula] = actores;
		}

		int N;  cin >> N;
		int maxVistoActor = 0;
		unordered_map<string, int> contador;
		map<string, int> actoresVistos;
		pair<string, int> ultimo;
		for (int i = 0; i < N; i++) {
			cin >> pelicula;
			ultimo.first = pelicula;
			contador[pelicula]++;
			if (m.count(pelicula)) {
				for (auto e : m[pelicula]) {
					actoresVistos[e.first] += e.second;
					if (maxVistoActor < actoresVistos[e.first])
						maxVistoActor = actoresVistos[e.first];
				}
			}
		}
		ultimo.second = contador.at(ultimo.first);

		//sacar la pelicula mas vista
		pair<string, int> max; max.second = 0;
		for (auto e : contador) {
			if (e.second > max.second) {
				max.second = e.second;
				max.first = e.first;
			}
		}
		if (max.second == ultimo.second)
			max = ultimo;


		//sacar al actor mas visto
		queue<string> actoresRes;
		for (auto e : actoresVistos) {
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