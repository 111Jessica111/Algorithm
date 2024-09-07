#include <stdio.h>

int p(int n, int m) {
	if (m == 1) return 1;
	if (m == n) return p(n, n - 1) + 1;
	if (m > n) return p(n, n);
	if (m < n) return p(n, m - 1) + p(n - m, m);
}

int main() {
	int num;
	int sum;
	scanf_s("%d", &num);
	sum = p(num, num);
	printf("%d\n", sum);
	return 0;
}