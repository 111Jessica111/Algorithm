#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, temp;
	for (i = 1; i > 0; i++) {
		temp = i * 7;
		if ((temp % 2 == 1) && (temp % 3 == 2) && (temp % 5 == 4) && (temp % 6 == 5) && (temp % 7 == 0)) {
			printf("%d", temp);
			return 0;
		}
	}
}