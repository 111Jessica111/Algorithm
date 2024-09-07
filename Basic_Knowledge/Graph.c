#include <stdio.h>
#include <malloc.h>

int visited[5] = { 0, 0, 0, 0, 0 };//Set all the vertexs in unvisited status

//Define a struct
typedef struct ArcNode {
	int adjvex;    //the position of the vertex to which the edge points
	struct ArcNode* next;//the next edge
}ArcNode;

typedef struct VNode {
	int data;
	ArcNode* firstarc;
}VNode;


//Initialize a graph
G_initGraph(VNode G[], int n) {
	int i, data;
	ArcNode* p, * q = NULL;
	printf("Input the information of the vertex\n");
	for (i = 0; i < n; i++) {
		scanf_s("%d", &G[i]);  //Getdata(G[i])
		G[i].firstarc = NULL;
	}
	for (i = 0; i < n; i++) {
		printf("Creat the edges for the %dth vertex\n",i);
		scanf_s("%d", &data);
		while (data != -1) {
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->next = NULL;
			p->adjvex = data;
			if (G[i].firstarc == NULL) G[i].firstarc = p;
			else {
				q->next = p;
			}
			q = p;
			scanf_s("%d", &data);
		}
	}
}

//Get this vertex's first adjvex
int Firstadj(VNode G[], int i) {
	if (G[i].firstarc != NULL) return (G[i].firstarc)->adjvex;
	else return -1;
}

//Get this vertex's next adjvex
int Nextadj(VNode G[], int i) {
	ArcNode* p;
	p = G[i].firstarc;
	while (p) {
		if (visited[p->adjvex] == 1) {
			p = p->next;//this vertes has already been visited ,turn to next vertex
		}
		else {
			return p->adjvex;
		}
	}
	return -1;
}

//DFS
void DFS(VNode G[], int i) {
	int j;
	printf("%d ", G[i].data);
	visited[i] = 1;  //set this vertex has already been visited
	j = Firstadj(G, i);
	while (j != -1) {
		if (visited[j] == 0) {
			DFS(G, j);
		}
		else {
			j = Nextadj(G, i);
		}
	}
}


int main() {
	VNode G[5];
	G_initGraph(G, 5);
	printf("DFS travel this undirected graph:\n");
	DFS(G, 0);
	for (int i = 0; i < 5; i++) {
		printf("%d ", visited[i]);
	}
	return 0;
}