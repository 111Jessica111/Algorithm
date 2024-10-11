#include<iostream>
#include <map>
#include<cstdio>
using namespace std;

std::map<int, std::map<int, int>> A;

int main_37() {
	int n, q, x, a, b;
	cin >> n >> q;
	while (q--) {
		cin >> x >> a >> b;
		if (x == 1) {
			cin >> A[a][b];
		}
		else {
			cout << A[a][b] << endl;
		}
	}
	return 0;
}