#include <stdio.h>

int Bin_Search(int A[], int n, int key) {
	int min, max, mid;
	min = 0;
	max = n - 1;

	while (min <= max) {
		mid = min + ((max - min) >> 1);
		if (A[mid] == key) return mid;
		else {
			if (A[mid] < key) {
				min = mid + 1;
			}
			if (A[mid] > key) {
				max = mid - 1;
			}
		}
	}
	return -1;
 }

int main() {
	int A[10] = {2,3,5,7,8,10,12,15,19,21};
	int key;
	int i;
	int length;
	length = 10;
	scanf_s("%d", &key);
	i = Bin_Search(A, length, key);
	if (i != -1) printf("The index of key is :%d\n", i);
	else printf("Can't find the key\n");
	return 0;
}