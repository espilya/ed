#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>


using namespace std;

#define DOMJUDGE


const std::string fin = "_FIN_";


void solve(int const& n) {
	int t;
	unordered_map <int, int> m;
	vector<int> order; 
	for (int i = 0; i < n; i++){
		cin >> t;
		if (m.find(t) == m.end())
			order.push_back(t); 
		m[t]++;
	}
	vector<pair<int, int>> list;
	for ( auto const &e : m) {
		list.push_back({ e.first , e.second });
	}
	for (auto const& e : order) {
		cout << e << ' ' << m.at(e) << endl;
	}
	std::cout << "---\n";
}


int main() {

	int n;
	while (cin >> n) {
		solve(n);
	}

}