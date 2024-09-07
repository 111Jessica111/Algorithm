#include <stdio.h>

//Enumerate and remove duplicates
int main() {
	int i, j, k;
	int sum = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5 ; j++) {
			for (k = 0; k < 5; k++) {
				if (i != j & j != k && k != i) {
					sum = sum + 1;
					printf("(%d,%d,%d) ", i, j, k);
				}

			}
		}
	}
	printf("%d\n", sum);
	return 0;
}