#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float Temp(int i) {
	if (i == 1) return (0.5) * 1;
	if (i > 1) return (0.5) * i * Temp(i - 1);
}

float SUM(int i) {
	if (i == 1) return Temp(i);
	if (i > 1) return Temp(i) + SUM(i - 1);
}

int main() {
	printf("%f", SUM(10));
	return 0;
}