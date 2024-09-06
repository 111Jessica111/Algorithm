#include <stdio.h>
#define MAXSIZE 10

//Insert a num in Sqlist, and estimate whether overflow
void Static_Insertnum(int Sqlist[], int Insnum, int data, int* len) {
	int p;
	if (Insnum > 10 || Insnum < 1 || *len == MAXSIZE) {
		printf("Out of range");
		return;
	}
	else {
		for (p = *len; p >= Insnum; p--) {
			Sqlist[p] = Sqlist[p - 1];
		}
		//printf("%d\n", p);
		Sqlist[p] = data;
		*len = *len + 1;
		printf("\nThe rest space is %d\n", MAXSIZE - *len);
	}
}

//Delete a num in Sqlist
void Static_Deletenum(int Sqlist[], int j, int* len) {
	int p;
	if (*len < 0 || j < 1 || j>10) {
		printf("Out of range");
		return;
	}
	for ( p=j -1; p < *len; p++){
		Sqlist[p] = Sqlist[p + 1];
	}
	Sqlist[p] = NULL;
	*len = *len - 1;
	printf("\nThe rest space is %d\n", MAXSIZE - *len);
}

int main_0() {
	int Sqlist[MAXSIZE];
	int i;
	int len;
	for (i = 0; i < 6; i++) {
		scanf_s("%d", &Sqlist[i]);
	}
	len = 6;
	for (i = 0; i < 6; i++) {
		printf("%d ", Sqlist[i]);
	}
	printf("\nThe rest space is %d\n", MAXSIZE - len);
	Static_Insertnum(Sqlist, 3, 0, &len);
	//for (i = 0; i < len; i++) {
	//	printf("%d ", Sqlist[i]);
	//}
	Static_Insertnum(Sqlist, 11, 0, &len);
	Static_Deletenum(Sqlist, 6, &len);
	for (i = 0; i < len; i++) {
	printf("%d ", Sqlist[i]);
	}
	return 0;
}


