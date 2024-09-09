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
	
##### 应用
	回溯法：
		从根结点开始探索；
		判断当前结点是否包含问题的解；
		若包含，则从该结点继续探索；
		若不包含，则返回上一结点继续探索，逐层回溯；
		
		应用：
			N皇后问题（经典）----！！！若该层无法寻找到相应值，切记将上一个归为0，即：
			for (i = 0; i < N; i++) {
				if (check(A, i, j)) {
				A[i][j] = 1;
				Queen(A, j + 1);
				A[i][j] = 0;      //！！！！！！
				}
			}


