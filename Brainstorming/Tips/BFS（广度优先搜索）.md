##### 基本逻辑
	从指定的顶点V0出发，访问所有与他邻接的顶点，再从邻接点出发，重复上述操作。
	按层搜索思路，采用最近点访问原则
##### 基本代码
	int Firstadj(VNode G[], int v){
		if(G[v].firstarc != NULL) return G[v].firstarc.adjvex;
		else return -1;
	}
	int Nextadj(VNode G[], int v){
		ArcNode *p;
		p=G[v].firstarc;
		while(p){
			if(visited[p->adjvex]) p=p->next;
			else return p->adjvex;
		}
		return -1;
	}
	BFS(VNode G[], int v){
		int w;
		visit(v);
		visited[v] = 1;
		Q_InsertQuelist(&q, v);
		while(!emptyQ(q)){
			Q_DeleteQuelist(&q,v);
			w = Firstadj(G, v);
			while(w != -1){
				if(visited[w] == 0){
					visit(w);
					Q_InsertQuelist(&q, w);
					visited[w] = 1;
				}
			w = Nextadj(G, v);
			}
		}
	}
