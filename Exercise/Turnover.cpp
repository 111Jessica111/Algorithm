#include <iostream>
#include <cmath> 
#include <vector>
using namespace std;

int Getmin(std::vector<int> a, int n, int min) {
	if (n == 1) {
		return std::abs(a[1] - a[0]);
	}
	else {
		for (int i = 0; i < n; i++) {
			min = (std::abs(a[n] - a[i])) < min ? std::abs(a[n] - a[i]) : min;
		}
		return min;
	}
}

int main_44() {
	int n, i, sum;
	cin >> n;
	int temp = n;
	i = 0;
	std::vector<int> a(n);
	while (temp--) {
		cin >> a[i++];
	}
	sum = a[0];
	for (i = 1; i < n; i++) {
		sum += Getmin(a, i, 10000000);
	}
	cout << sum << endl;
	return 0;
}