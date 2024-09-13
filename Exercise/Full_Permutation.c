#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

Perm(int a[], int n, int s, int r[], int m) {
	int i, j, k, flag = 0;
	int b[MAX];
	for (i = 0; i < n; i++) {
		flag = 1;
		r[s] = a[i];
		j = 0;
		for (k = 0; k < n; k++) {//make the subsequence
			if (i != k) {
				b[j] = a[k];
				j++;
			}
		}
		Perm(b, n - 1, s + 1, r, m);//Full permutation the subsequence
	}
	if (flag == 0) {
		for (k = 0; k < m; k++) {
			printf("%d ", r[k]);
		}
		printf("\n");
	}
}

int main() {
	int n, i;
	int a[MAX], r[MAX];
	printf("Please input the number of digit in the array\n");
	scanf("%d", &n);
	printf("Please input a string for array\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	Perm(a, n, 0, r, n);
	return 0;  
}