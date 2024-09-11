#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int sum = 1;
	int i;
	for (i = 9; i > 0; i--) {
		sum = (sum + 1) * 2;
	}
	printf("%d", sum);
	return 0;
}