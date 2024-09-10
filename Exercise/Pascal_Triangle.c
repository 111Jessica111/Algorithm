#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 4

void Pascal_Triangle(int n, int A[], int B[]) {
	int i, temp;
	for (i = 0; i <= n; i++) {
		if (i == 0) {
			for (temp = 0; temp < n + 1; temp++) {
				printf(" ");
			}
			printf("1 ");
			temp = 0;
		}
		else {
			if (i == 1) {
				for (temp = 0; temp < n; temp++) {
					printf(" ");
				}
				printf("1 1");
				B[0] = B[1] = 1;
			}
			else {
				int j;
				for (j = 0; j <= i; j++) {
					if (j == 0 || j == i) {
						if (j == 0) {
							for (temp = 0; temp < n - i + 1; temp++) {
								printf(" ");
							}
						}
						printf("1 ");
						A[j] = 1;
					}
					else {
						printf("%d ", B[j - 1] + B[j]);
						A[j] = B[j - 1] + B[j];
					}
				}
				for (int k = 0; k <= n; k++) {
					B[k] = A[k];
				}
			}
		}
		printf("\n");
	}
}


int main() {
	int A[N + 1], B[N + 1];
	Pascal_Triangle(N, A, B);
	return 0;
}