#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;



typedef struct {
	string fecha;
	double muertos;
}tAcc;



int main() {

	vector<tAcc> v;
	tAcc t;
	string t1;
	double t2;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		t.fecha = t1; t.muertos = t2;
		v.push_back(t);

		if (i > 1) {
			int j = v.size() - 2;
			bool found = false;
			while (j >= 0 && !found) {
				if (v[j].muertos > t.muertos)
					found = true;
				else
					j--;
			}
			if (found)
				cout << v[j].fecha << endl;
			else
				cout << "NO HAY" << endl;
		}
		else 
			cout << "NO HAY" << endl;
	}
	cout << "---" << endl;


}

