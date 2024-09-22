#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void biTOde(int* sum, int* m, int n) {
	char c;
	scanf("%c", &c);
	if (c != '#') {
		*m = *m + 1;
		biTOde(&(*sum), &(*m), n + 1);
	}
	if (c == '1') {
		*sum = *sum + pow(2, (*m) - n - 1);
	}
}


int main() {
	int sum;
	int m;
	sum = m = 0;
	biTOde(&sum, &m, 0);
	printf("sum:%d", sum);
	return 0;
}