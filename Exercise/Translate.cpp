#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main_42() {
	std::queue<int> q;
	int n, m;
	int i;
	int count = 0;
	cin >> m >> n;
	std::vector<int> a(n + 1);
	std::vector<int> b(1001);
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (i = 1; i <= n; i++) {
		if (b[a[i]] == 0) {
			if (count < m) {
				q.push(a[i]);
				b[a[i]] = 1;
				count++;
			}
			else {
				b[q.front()] = 0;
				q.pop();
				q.push(a[i]);
				b[a[i]] = 1;
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}