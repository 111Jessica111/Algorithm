#include <stdio.h>
#include <malloc.h>

//Define a struct
typedef struct BitNode {
	char data;
	struct BitNode* lchild, * rchild;
}BitNode, * BiTree;

//Initialize a Treelist
 initTreelist(BiTree* t) {
	char c;
	scanf_s("%c", &c);
	if (c == ' ') *t = NULL;
	else {
		*t = (BiTree)malloc(sizeof(BitNode));
		(*t)->data = c;
		initTreelist(&((*t)->lchild));
		initTreelist(&((*t)->rchild));
	}
}

//Visit the base point
 visit(char c, int level) {
	if (c == 'D') {
		printf("The word D is at level %d", level);
	}
}

//Preorder traversal
 T_PreorderTraversal(BiTree t, int level){
	if (t) {
		visit(t->data, level);
		T_PreorderTraversal(t->lchild, level + 1);
		T_PreorderTraversal(t->rchild, level + 1);
	}
}


int main() {
	int level = 1;
	BiTree T = NULL ;
	initTreelist(&T);
	T_PreorderTraversal(T, level);
	return 0;
}