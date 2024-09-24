#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Triangle(int a[100], int n) {
	int i, j, k;
	int flag = 0;
	int b[100];
	for (i = 0; i < n; i++) {
		b[i] = a[i];
	}
	for (i = 0; i < n - 2 && b[i] != -1; i++) {
		for (j = i + 1; j < n - 1 && b[j] != -1; j++) {
			for (k = j + 1; k < n && b[k] != -1; k++) {
				if ((a[i] + a[j] > a[k]) && (a[i] + a[k] > a[j] )&& (a[k] + a[j] > a[i])) {
					printf("%d %d %d\n", a[i], a[j], a[k]);
					b[i] = -1;
					b[j] = -1;
					b[k] = -1;
					return;
				}
			}
		}
	}
	printf("No solution");
}

int main_27() {
	int n;
	int i;
	int a[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	//for (i = 0; i < n; i++) {
	//	printf("%d ", a[i]);
	//}
	Triangle(a, n);
	return 0;
}