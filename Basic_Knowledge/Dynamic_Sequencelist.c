#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#define MAXSIZE 10

//Define a struct
typedef struct {
	int *data;//source ip
	int length;//update length
	int listsize;//MAXSIZE
}Sqlist;

//Initialize Sqlist
void Dynamic_InitSqlist(Sqlist* l) {
	l->data = (int*)malloc(MAXSIZE * sizeof(int));
	if (!l->data) exit(0);
	l->length = 0;
	l->listsize = MAXSIZE;
}

//Insertnum in Sqlist
void Dynamic_Insertnum(Sqlist* l, int data, int i) {
	int* base, * InsertPtr, * p ;
	if (i<1 || i> l->length + 1) {
		exit(0);
	}
	if (l->length >= l->listsize) {
		base = (int*)realloc(l->data, (l->listsize + 10) * sizeof(int));
		l->data = base;
		l->listsize = l->listsize + 100;
	}
	InsertPtr = &(l->data[i - 1]);
	for (p = &(l->data[l->length - 1]); p >= InsertPtr; p--) {
		*(p + 1) = *p;
	}
	*InsertPtr = data;
	l->length = l->length + 1;
}
//Delete a num in Sqlist
void Dynamic_Deletenum(Sqlist* l, int i) {
	int* DeletePtr, * p;
	if (i<1 || i>l->length - 1) exit(0);
	DeletePtr = &(l->data[i - 1]);
	for (p = DeletePtr; p < &(l->data[l->length - 1]); p++) {
		*p = *(p + 1);
	}
	*p = NULL;
	l->length = l->length - 1;
}

int main_1() {
	Sqlist l;
	int i;
	Dynamic_InitSqlist(&l);
	for (i = 0; i < 15; i++) {
		Dynamic_Insertnum(&l, i + 1, i + 1);
	}
	for (i = 0; i < l.length; i++) {
		printf("%d ", l.data[i]);
	}
	printf("\n");
	Dynamic_Deletenum(&l, 5);
	for (i = 0; i < l.length; i++) {
		printf("%d ", l.data[i]);
	}
	return 0;
}