#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int match(int i, int j, int k, char Wife[]) {
	if (Wife[i] == 'X') return 0;//A not with X
	if (Wife[k] == 'X') return 0;//C not with X
	if (Wife[k] == 'Z') return 0;//C not with Z
	return 1;
}


int main() {
	char Husband[3] = { 'A','B','C' };
	char Wife[3] = { 'X','Y','Z' };
	int i, j, k;
	for (i = 0; i < 3; i++) {//A match
		for (j = 0; j < 3;j++) {//B match
			for (k = 0; k < 3; k++) {//C match
				if (i != j && j != k && i != k) {
					if (match(i, j, k, Wife)) {
						printf("A %c\n", Wife[i]);
						printf("B %c\n", Wife[j]);
						printf("C %c\n", Wife[k]);
					}
				}
			}
		}
	}
	return 0;
}