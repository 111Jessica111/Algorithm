#include <stdio.h>
#include <malloc.h>

//Define a struct
typedef struct QNode {
	char data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr real;
}LinkQueue;

//Initialize a Queuelist
Q_InitQuelist(LinkQueue* q) {
	q->front = q->real = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front) exit(0);
	q->front->next = NULL;
}

//Insert a num in Queuelist
void Q_InsertQuelist(LinkQueue* q, char data) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front) exit(0);
	p->data = data;
	p->next = NULL;
	q->real->next = p;
	q->real = p;
}

//Delete a num in Queuelist
void Q_DeleteQuelist(LinkQueue* q,char* elem) {
	QueuePtr p;
	if (q->front == q->real) return;
	else {
		/*printf("%c", *elem);*/
		p = q->front->next;
		*elem = p->data;
		//printf("%c", *elem);
		q->front->next = p->next;
		if (q->real == p) q->real = q->front;  //the last one
		free(p);
		
	}
}


int main_4() {
	char data;
	LinkQueue q;
	Q_InitQuelist(&q);
	printf("Please input a string into a queue:\n");
	scanf_s("%c", &data);
	while (data != '@') {
		Q_InsertQuelist(&q, data);
		//getchar();  // write this will clear the button "Enter"
		scanf_s("%c", &data);

	}

	printf("The string into the queue is:\n");
	while (q.front != q.real) {
		Q_DeleteQuelist(&q, &data);
		printf("%c", data);
	}
	printf("\n");
	//getchar();
	return 0;
}