#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 1000
#define MIN 100

int Narcissistic(int n) {
	int i;
	int X = n;
	int Y = 0;
	while (n) {
		Y = Y + pow((n % 10), 3);
		n = n / 10;
	}
	if (Y == X) return 1;
	else return 0;
}

int main() {
	int i;
	int count = 0;
	for (i = MIN; i < MAX; i++) {
		if (Narcissistic(i)) {
			printf("%d ", i);
			count++;
		}
	}
	return 0;
}