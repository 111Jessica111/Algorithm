#include <stdio.h>
#include <malloc.h>
#define MAX_SPACE 13

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//Make the t[] store the orded index
void sort(int t[], int A[], int n) {
	int i, j;
	int *a = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		a[i] = A[i];
		t[i] = i;
	}
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				swap(&t[j], &t[j + 1]);
			}
		}
	}
	//for (i = 0; i < n; i++) {
	//	printf("%d ", t[i]);
	//}
	//printf("\n");
	//for (i = 0; i < n; i++) {
	//	printf("%d ", a[i]);
	//}
	//printf("\n");
}

int Loading(int A[], int X[], int n ,int MAX) {
	int i;
	int *t = (int*)malloc(n * sizeof(int));  //Store subscripts
	sort(t, A, n);
	//for (i = 0; i < n; i++) {
	//	printf("%d ", t[i]);
	//}
	//printf("\n");
	for (i = 0; i < n && MAX >= A[t[i]]; i++) {
		X[t[i]] = 1;
		MAX = MAX - A[t[i]];
	}
	return MAX;
}

int main() {
	int A[100]; 
	int X[100]; //check whether haa been loaded
	int i = 0;
	int n = 0, weigth;
	int rest;
	scanf_s("%d", &weigth);
	while (weigth != -1 && i < 100) {
		A[i] = weigth;
		i++;
		scanf_s("%d", &weigth);
	}
	n = i;
	for (i = 0; i < n; i++) {
		X[i] = 0;
	}
	rest = Loading(A, X, n, MAX_SPACE);
	for (i = 0; i < n; i++) {
		if (X[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
	printf("The rest weigth is:%d", rest);
	return 0;
}