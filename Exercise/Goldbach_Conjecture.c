#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 4000

int Prime(int num) {
	int i;
	for (i = 2; i <= pow(num, 0.5); i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}

int Prime_check(int x) {
	int i;
	for (i = 2; i <= (x / 2); i++) {
		if (Prime(i) == 1 && Prime(x - i) == 1) {
			return 1;
		}
	}
	return 0;
}

int Goldbach_Conjecture(int n) {
	int i;
	for (i = 4; i <= n; i++) {
		if (i % 2 == 0) {
			if (!Prime_check(i)) return 0;
		}
	}
	return 1;
}


int main() {
	if (Goldbach_Conjecture(MAX)) {
		printf("Right");
	}
	else {
		printf("False");
	}
	return 0;
}