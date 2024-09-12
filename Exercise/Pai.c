#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100000

double Pai_1(int n) {
	int sum = 0;
	int i;
	float x, y;
	time_t t;
	srand((unsigned)time(&t));
	for (i = 1; i <= n; i++) {
		//x = rand() % 100 / 100.0;
		//y = rand() % 100 / 100.0;
		//if (y <= sqrt(1 - x * x)) {
		//	sum++;
		//}
		x = rand() % 100;
		y = rand() % 100;
		if (x * x + y * y <= 10000) {
			sum++;
		}

	}
	return 4.0 * (double)sum /(double) n;
}

double Pai_2(int n) {
	int div;
	int i = 4;
	double c = 0.0;
	double b = sqrt(2)/2.0;
	for (div = 0; div < n; div++) {
		b = sqrt(2.0 - 2.0 * sqrt(1.0 - b * b)) * 0.5;
		i = 2 * i;
	}
	c = i * b;
	return c;
}



int main() {
	int n;
	scanf("%d", &n);
	printf("%f\n", Pai_1(MAX));
	printf("%f\n", Pai_2(n));
	return 0;
}