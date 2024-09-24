#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000
#define MIN 1000

int main_28() {
	int i;
	int x;
	int a, b;
	for (i = MIN; i < MAX; i++) {
		x = i;
		a = i % 100;
		b = i / 100;
		if ((a + b) * (a + b) == x) {
			printf("%d  ", x);
		}
	}
	return 0;
}