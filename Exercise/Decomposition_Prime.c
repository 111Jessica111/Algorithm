#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int Right(int x) {
	int i;
	for (i = 2; i <= pow(x, 0.5); i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

Decomposition(int num) {
	int i;
	if (Right(num)) {
		printf("%d ", num);
	}
	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			printf("%d ", i);//the first i must be prime;
			num = num / i;
			if (Right(num)) {
				printf("%d ", num);
				break;
			}
			else {
				Decomposition(num);
			}
			break;
		}
	}	
}

int main() {
	int num;
	scanf("%d", &num);
	Decomposition(num);
	return 0;
}