#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Bubblesort(int A[], int length) {
	int i, j;
	for (i = 0; i < length - 1; i++) {
		for (j = 0; j < length -1- i; j++) {
			if (A[j] > A[j + 1]) swap(&A[j], &A[j + 1]);
		}
	}
}

int main() {
	int A[100];
	int i, length;
	int num;
	scanf_s("%d", &num);
	for (i = 0; i < 100 && num != -1; i++) {
		A[i] = num;
		scanf_s("%d", &num);
	}
	length = i;
	Bubblesort(A, length);
	for (i = 0; i < length; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}