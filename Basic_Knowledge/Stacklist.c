#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define MAX_STACK_SIZE 10
#define STACKINSERTSIZE 5

//Define a struct
typedef struct {
	char* top;
	char* base;
	int stacksize;
}sqStack;

//Initialize a stacklist
S_Initstacklist(sqStack* s) {
	s->base = (char*)malloc(MAX_STACK_SIZE * sizeof(char));
	if (!s->base) exit(0);
	s->top = s->base;
	s->stacksize = MAX_STACK_SIZE;
}

//Insert a num in stacklist
void S_Insertstacknum(sqStack* s, char data) {
	char* new_base;
	if ((s->top - s->base) >= s->stacksize) {
		s->base = (char*)realloc(s->base, (MAX_STACK_SIZE + STACKINSERTSIZE) * sizeof(char));
		if (!s->base) exit(0);
		s->top = s->base + MAX_STACK_SIZE;
		s->stacksize = s->stacksize + STACKINSERTSIZE;
	}
	*(s->top) = data;
	s->top++;
}

//Delete a num in stacklist
void S_Deletestacknum(sqStack* s,char* data) {
	if (s->top == s->base) return;
	*data = *--(s->top);
}

//The length of stacklist
int S_Length(sqStack s) {
	return(s.top - s.base);
}

//Convert binary to decimal
int main_3() {
	char data = NULL,b_data = NULL;
	sqStack s;
	int num = 0, len, i;
	S_Initstacklist(&s);
	//printf("true");
	scanf_s("%c", &data);
	while (data != '#') {
		S_Insertstacknum(&s, data);
		getchar();
		scanf_s("%c", &data);
	}
	len = S_Length(s);
	//printf("%d\n", len);
	for (i = 0; i < len; i++ ) {
		S_Deletestacknum(&s,&b_data);
		num = num +(b_data - 48) * pow(2, i);
		//printf("%d ", b_data - 48);
	}
	printf("\n%d", num);
	return 0;
}