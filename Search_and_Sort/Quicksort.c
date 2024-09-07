#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Quicksort(int A[], int left, int right) {
	int l = 0;
	int r = 0;
	if (left < right) {
		l = left;
		r = right;
		while (l < r) {
			while (A[r] > A[left] && l < r) {
				r--;
			}
			while (A[l] < A[left] && l < r) {
				l++;
			}
			if (l < r) swap(&A[l], &A[r]);
		}
		swap(&A[l], &A[left]);
		Quicksort(A, left, l - 1);
		Quicksort(A, l + 1, right);
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
	Quicksort(A, 0, length - 1);
	for (i = 0; i < length; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}