#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, j, k;
	int sum = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 2; k < 7; k++) {
				if (i + k + j == 8) {
					printf("Red:%d Yellow:%d Green:%d\n", i, j, k);
					sum++;
				}
			}
		}
	}
	printf("Sum:%d\n", sum);
	return 0;
}