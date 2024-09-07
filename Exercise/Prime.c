#include <stdio.h>
#include <math.h>

int Prime(int num) {
	int i;
	for (i = 2; i <= pow(num, 0.5); i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}

int main_0() {
	int i = 0;
	for (i = 1; i <= 100; i++) {
		if (Prime(i)) {
			printf("%d ", i);
		}
	}
	return 0;
}