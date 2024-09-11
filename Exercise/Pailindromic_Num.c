#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 1000
#define MIN 100

int Pailindromic(int i) {
	int X  = 0, Y;
	int k;
	Y = i;
	k = 2;
	while (i) {
		X = X + (i % 10) * pow(10, k);
		i = i / 10;
		k--;
	}
	if (X == Y) return 1;
	else return 0;
}

int main() {
	int i;
	for (i = MIN; i < MAX; i++) {
		if (Pailindromic(i)) {
			printf("%d ", i);
		}
	}
	return 0;
}