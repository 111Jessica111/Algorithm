#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 21

int main() {
	int n;
	int x;
	n = MAX;
	while (n) {
		printf("Input the num of your part:\n");
		scanf("%d", &x);
		printf("My part is:\n");
		printf("%d\n", 5 - x);
		n = n - 5;
		if (n == 1) {
			printf("Lose");
			break;
		}
	}
	return 0;
}