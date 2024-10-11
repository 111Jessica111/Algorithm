#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void Input_SUM(int sum, int SUM[], int** B, int n) {
	int i, j;
	if (sum > SUM[1] && sum < SUM[0]) {
		SUM[1] = sum;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%2d ", B[i][j]);
			}
			printf("\n");
		}
		printf("%d\n",sum);
		//for (i = 0; i < n; i++) {
		//	for (j = 0; j < n; j++) {
		//		B[i][j] = 0;
		//	}
		//}
		//printf("\n");
		return;
	}
	else if (sum > SUM[1] && sum > SUM[0]) {
		SUM[0] = sum;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%2d ", B[i][j]);
			}
			printf("\n");
		}
		printf("%d\n",sum);
		//for (i = 0; i < n; i++) {
		//	for (j = 0; j < n; j++) {
		//		B[i][j] = 0;
		//	}
		//}
		return;
	}
	else {
		return;
	}
}

void Find_MAX_SUM(int** A, int** B, int SUM[], int x, int y, int n, int sum) {
	B[x][y] = 1 ;
	if (x == n - 1 && y == n - 1) {
		//if (sum != 0) {
		//	printf("%d\n", sum);
		//}
		Input_SUM(sum, SUM, B, n);
		return;
	}
	else {
		if (x + 1 < n && y < n) {
			sum += A[x + 1][y];
			Find_MAX_SUM(A, B, SUM, x + 1, y, n, sum);
			sum -= A[x + 1][y];
			B[x + 1][y] = 0;
		}
		if (x < n && y + 1 < n) {
			sum += A[x][y + 1];
			Find_MAX_SUM(A, B, SUM, x, y + 1, n, sum);
			sum -= A[x][y + 1];
			B[x][y + 1] = 0;
		}
	}
}

int main_32() {
	int n;
	int i, j;
	int x, y, num;
	int sum;
	int SUM[2] = { -1,-2 };
	scanf("%d", &n);
	int** A = (int**)malloc(n * sizeof(int*));
	int** B = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) {
		A[i] = (int*)malloc(n * sizeof(int));
		B[i] = (int*)malloc(n * sizeof(int));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = 0;
			B[i][j] = 0;
		}
	}
	scanf("%d %d %d", &x, &y, &num);
	while (x != 0 && y != 0 && num != 0) {
		A[x - 1][y - 1] = num;
		scanf("%d %d %d", &x, &y, &num);
	}
	sum = A[0][0];
	//for (i = 0; i < n; i++) {
	//	for (j = 0; j < n; j++) {
	//		printf("%2d ", A[i][j]);
	//	}
	//	printf("\n");
	//}
	Find_MAX_SUM(A, B, SUM, 0, 0, n, sum);
	printf("%d %d", SUM[0], SUM[1]);
	return 0;
}