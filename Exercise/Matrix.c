#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap1(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Conversion(int B[4][3],int A[3][4]) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			B[i][j] = A[j][i];
		}
	}
}

int main() {
	int A[3][4], B[4][3], C[3][3];
	int i, j, k;
	int elem;
	int sum = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}
	printf("\n");
	Conversion(B, A);
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < 3; i++) {
		for (k = 0; k < 3; k++) {
			sum = 0;
			for (j = 0; j < 4; j++) {
				sum += A[i][j] * B[j][k];
			}
			C[i][k] = sum;
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}