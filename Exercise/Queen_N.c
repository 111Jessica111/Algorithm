#include <stdio.h>
#define N 8

int count = 0;

int check(int A[N][N], int i, int j) {
	int s, t;
	//line
	for (t = 0, s = i; t < N; t++) {
		if (A[s][t] == 1 && t != j) return 0;
	}
	//column
	for (s = 0, t = j; s < N; s++) {
		if (A[s][t] == 1 && s != i) return 0;
	}
	//lower left
	for (s = i + 1, t = j - 1; t >= 0 && s <= N - 1; s++, t--) {
		if (A[s][t] == 1) return 0;
	}
	//upper left
	for (s = i - 1, t = j - 1; t >= 0 && s >= 0; s--, t--) {
		if (A[s][t] == 1) return 0;
	}
	//lower right
	for (s = i + 1, t = j + 1; t <= N - 1 && s <= N - 1; s++, t++){
		if (A[s][t] == 1) return 0;
	}
	//upper right
	for (s = i - 1, t = j + 1; t <= N - 1 && s >= 0; s--, t++){
		if (A[s][t] == 1) return 0;
	}
	return 1;
}

void Queen(int A[N][N], int j) {
	int i, k;
	if (j == N) {
		for (i = 0; i < N; i++) {
			for (k = 0; k < N; k++) {
				printf("%d ", A[i][k]);
			}
			printf("\n");
		}
		printf("\n");
		count++;
		return;
	}
	for (i = 0; i < N; i++) {
		if (check(A, i, j)) {
			A[i][j] = 1;
			Queen(A, j + 1);
			A[i][j] = 0;      //when this level can't find a correct place, set the upper point 0
		}
	}
}

int main() {
	int A[N][N];
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			A[i][j] = 0;
		}
	}
	Queen(A, 0);
	printf("\ntotal:%d\n", count);
	return 0;
}