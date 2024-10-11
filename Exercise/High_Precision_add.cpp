#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main_33() {
	string n, m;
	int n_len, m_len;
	int a[502] = {0};
	int b[502] = {0};
	int c[502] = {0};
	int i, j;
	int flag = 0;
	cin >> n;
	cin >> m;
	n_len = n.size();
	m_len = m.size();
	for (i = 500,j= n_len-1; j >= 0; j--, i--) {
		a[i] = n[j] - 48;
	}
	for (i = 500, j = m_len - 1; j >= 0; j--, i--) {
		b[i] = m[j] - 48;
	}
	for (i = 500; i >= 0; i--) {
		c[i] = a[i] + b[i] + flag;
		flag = 0;
		if (c[i] >= 10) {
			c[i] -= 10;
			flag = 1;
		}
	}
	for (i = 0; i < 500; i++) {
		if (c[i] != 0) break;
	}
	for (j = i; j < 501; j++) {
		printf("%d", c[j]);
	}
	return 0;
}
