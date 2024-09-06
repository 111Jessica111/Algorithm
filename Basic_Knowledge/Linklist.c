#include <stdio.h>
#include <malloc.h>

//Define a stuct
typedef struct Node {
	int data;
	struct Node* next;
}LNode, * Linklist;

//Initialize Linklist
Linklist CreateLinklist(int n) {
	Linklist p = NULL, r = NULL, head = NULL;
	int e;
	int i;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &e);
		p = (Linklist)malloc(sizeof(LNode));
		p->data = e;
		p->next = NULL;
		//head == null
		if (!head) {
			head = p;
		}
		else{
			r->next = p;
		}
		r = p;
	}
	return head;
}

//Insert a point in Linklist
void L_Insertpoint(Linklist* head, int e, Linklist q) {
	Linklist p;
	p = (Linklist)malloc(sizeof(LNode));
	p->data = e;
	p->next = NULL;
	//point is head
	if (!*head) {        
		head = p;
	}
	else {
		p->next = q->next;
		q->next = p;
	}
}

//Delete a point in linklist
void L_Deletepoint(Linklist* head, int n) {
	int i;
	Linklist p = *head, r;
	for (i = 0; i < n-1; i++) {
		p = p->next;
	}
	if (*head == p) {//check head = q   correct
		p->next = *head;
		free(p);
	}
	else {
		for (r = *head; r->next != p; r = r->next);
		if (r->next != NULL) {
			r->next = p->next;
			free(p);
		}
	}
}

//Destroy Linklist
void L_Destroylist(Linklist* head) {
	Linklist p, q;
	p = *head;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	*head = NULL;
}

int main_2() {
	//int i;
	//Linklist p, head;
	//p = CreateLinklist(3);
	//for (i = 0; i < 3; i++) {
	//	printf("%d ", p->data);
	//	p = p->next;
	//}

	int e, i;
	Linklist l, q;
	q = l = CreateLinklist(1);
	scanf_s("%d", &e);
	while (e) {
		L_Insertpoint(&l, e, q);
		q = q->next;
		scanf_s("%d", &e);
	}
	q = l;
	printf("The content of Linklist:\n");
	while (q) {
		printf("%d ", q->data);
		q = q->next;
	}
	printf("\n");
	q = l;
	L_Deletepoint(&l, 5);//delete the fifth
	q = l;
	printf("The content of Linklist:\n");
	while (q) {
		printf("%d ", q->data);
		q = q->next;
	}
	L_Destroylist(&l);
	return 0;
}