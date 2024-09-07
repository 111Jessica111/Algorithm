#include <stdio.h>

void swap_1(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Selectsort(int A[], int length) {
	int i;
	int j;
	for (i = 0; i < length; i++) {
		int min_index = i;
		for (j = i + 1; j < length; j++) {
			if (A[min_index] > A[j]) min_index = j;
		}
		if (min_index != i) {
			swap(&A[i], &A[min_index]);
		}
	}
}


int main_3() {
	int A[100];
	int i, length;
	int num;
	scanf_s("%d", &num);
	for (i = 0; i < 100 && num != -1; i++) {
		A[i] = num;
		scanf_s("%d", &num);
	}
	length = i;
	Selectsort(A, length);
	for (i = 0; i < length; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}