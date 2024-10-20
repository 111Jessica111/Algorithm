#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

struct node1 {
	int l, r;
}a[1001000];

int MAX = -1;

void dfs(int root, int step) {
	if (root == 0) return;
	MAX = max(MAX, step);
	dfs(a[root].l, step + 1);
	dfs(a[root].r, step + 1);
}

int main_46() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r;
	}
	dfs(1, 1);
	cout << MAX;
	return 0;
}