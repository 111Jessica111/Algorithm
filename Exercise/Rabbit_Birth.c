#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TIME 12

int Rabbit(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n > 2) return Rabbit(n - 1) + Rabbit(n - 2);
}

int main() {
	printf("%d", Rabbit(TIME));
	return 0;
}