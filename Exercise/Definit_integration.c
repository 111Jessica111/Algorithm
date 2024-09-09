#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double Darts(int n) {
	double x, y;
	int i;
	int count = 0;
	time_t t;
	srand((unsigned)time(&t));
	for (i = 0; i < n; i++) {
		//To make sure x and y can get all the num in 0 to 1;
		//should use 100.0 :rand() % 100 / 100.0;
		//make sure x and y are floats;
		x = rand() % 100 / 100.0;
		y = rand() % 100 / 100.0;
		if (y <= 1 - pow(x, 2)) {
			count++;
		}
	}
	return (double)count / (double)n;
}

int main() {
	int n;
	printf("Input the accuracy:\n");
	scanf_s("%d", &n);
	printf("%f\n", Darts(n));
	return 0;
}