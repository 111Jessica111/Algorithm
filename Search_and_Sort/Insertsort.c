#include <stdio.h>

void swap_0(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Insertsort(int A[],int n) {
	int i;
	int j;
	for (i = 1; i < n; i++) {
		for (j = i; j > 0; j--) {
			if (A[j] < A[j - 1]) swap(&A[j], &A[j-1]);
			else break;
		}
	}
}

int main_2() {
	int A[100];
	int i, length;
	int num;
	scanf_s("%d", &num);
	for (i = 0; i < 100 && num != -1; i++) {
		A[i] = num;
		scanf_s("%d", &num);
	}
	length = i;
	//now i is the length of A[]
	Insertsort(A, length);
	for (i = 0; i < length; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}