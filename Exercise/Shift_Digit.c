#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void GetStep(int M[]) {
	int i, j, temp;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7 - i; j++) {
			if (M[j] > M[j + 1]) {
				temp = M[j];
				M[j] = M[j + 1];
				M[j + 1] = temp;
				printf("%d#--->0#\n", M[j]);
				printf("%d#--->%d#\n", M[j + 1], M[j]);
				printf("0#--->%d\n", M[j + 1]);
			}
		}
	}

}

void Print(int M[]) {
	printf("[%d]--[%d]--[%d]\n", M[0], M[1], M[2]);
	printf(" |  %c |  %c |\n", 92, 47);
	printf("[%d]--[ ]--[%d]\n", M[7], M[3]);
	printf(" |  %c |  %c |\n", 47, 92);
	printf("[%d]--[%d]--[%d]\n", M[6], M[5], M[4]);
}


int main() {
	int i, M[8];
	for (i = 0; i < 8; i++) {
		scanf("%d", &M[i]);
	}
	Print(M);
	GetStep(M);
	Print(M);
	return 0;
}