#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


int Find_Carpet(int x, int y, int A[], int n) {
	int index = -1;
	int i;
	for (i = 4 * n-4; i >=0; i -= 4) {
		if (x <= A[i] + A[i + 2] && x >= A[i] && y <= A[i + 1] + A[i + 3] && y >= A[i + 1]) {
			index = (i / 4) + 1;
			return index;
		}
	}
	return index;
}

int main_31() {
	int n;
	int i, j;
	int x, y;
	scanf("%d", &n);
	int* A = (int*)malloc(n * 4 * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < 4; j++) {
			scanf("%d", &A[i * 4 + j]);
		}     
	}
	//for (i = 0; i < n; i++) {
	//	for (j = 0; j < 4; j++) {
	//		printf("%d", A[i * 4 + j]);
	//	}
	//	printf("\n");
	//}
	scanf("%d %d", &x, &y);
	printf("%d\n", Find_Carpet(x, y, A, n));
	return 0;
}