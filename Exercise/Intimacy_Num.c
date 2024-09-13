#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 3000

int Sum(int x) {
	int j, k;
	int sum = 0;
	for (j = 1; j < x; j++) {
		int k = x;
		if (k % j == 0) {
			k = k / j;
			sum = sum + j;
		}
	}
	return sum;
}

int main() {
	int m, n;
	int i;
	for (i = 2; i < MAX; i++) {
		m = Sum(i);
		n = Sum(m);
		if (n == i && n != m) {
			printf("<%d %d> ", i,m);
		}
	}
	return 0;
}