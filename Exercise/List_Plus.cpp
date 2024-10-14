#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
    int L, R;
}a[100003];
int n, m;

//插入右边 
inline void addRight(int x, int pos) { 
    a[x].L = pos;//将预计数的左边指向pos
    a[a[pos].R].L = x;//将后一个数的左边指向预计数
    a[x].R = a[pos].R;//将预计数的右边指向原pos右边的数
    a[pos].R = x;//将pos的右边指向预计数
}

//插入左边
inline void addLeft(int x, int pos) { 
    a[x].R = pos;
    a[a[pos].L].R = x;
    a[x].L = a[pos].L;
    a[pos].L = x;
}

//删除
inline void del(int x) {
    if (a[x].L == -1) return;
    a[a[x].L].R = a[x].R;
    a[a[x].R].L = a[x].L;
    a[x].L = -1;
    a[x].R = -1;
}

//输出链表
inline void go() {
    int x = a[0].R;
    while (1) {
        cout << x << " ";
        if (a[x].R == -1) break;
        x = a[x].R;
    }
}

//初始化链表
inline void init() {
    for (int i = 1; i <= n; ++i) a[i].L = a[i].R = -1;
    a[1].R = -1; a[1].L = 0; a[0].R = 1;
}

//双链表表示

int main_39() {
    scanf("%d", &n);
    int cmd1, cmd2;
    init();
    for (int i = 2; i <= n; ++i) {
        scanf("%d %d", &cmd1, &cmd2);
        if (!cmd2) addLeft(i, cmd1);
        else addRight(i, cmd1);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &cmd1);
        del(cmd1);
    }
    go();
    return 0;
}