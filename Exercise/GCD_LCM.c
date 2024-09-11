#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GCD(int x, int y) {
	int i, min;
	min = x < y ? x : y;
	for (i = min; i > 1; i--) {
		if (x % i == 0 && y % i == 0) {
			return i;
		}
	}
	return 0;
}

int LCM(int x, int y) {
	int i;
	int max;
	max = x > y ? x : y;
	i = max;
	while (1) {
		if (i % x == 0 && i % y == 0) {
			return i;
		}
		i++;
	}
}

int main() {
	int x, y;
	int gcd, lcm;
	scanf("%d %d", &x, &y);
	gcd = GCD(x, y);
	if (gcd) {
		printf("The GCD is : %d\n", gcd);
	}
	lcm = LCM(x, y);
	printf("The LCM is : %d\n", lcm);
	return 0;
}