##### 基本逻辑
	指定一顶点V0出发，搜索V0的第一个邻接点，搜索V0的第二个邻接点，...，搜索V0的第N个邻接点。
	从一点深入，直到不能再深入为止。

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
	void DBS(VNode G[], int v){
		int w;
		visit(v);
		visited[v] = 1;
		w = Firstadj(G, v);
		while(w != -1){
			if(visited[w] == 0) DFS(G, w);
			w = Nextadj(G, v);
		}
	}