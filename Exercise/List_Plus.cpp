#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
    int L, R;
}a[100003];
int n, m;

//�����ұ� 
inline void addRight(int x, int pos) { 
    a[x].L = pos;//��Ԥ���������ָ��pos
    a[a[pos].R].L = x;//����һ���������ָ��Ԥ����
    a[x].R = a[pos].R;//��Ԥ�������ұ�ָ��ԭpos�ұߵ���
    a[pos].R = x;//��pos���ұ�ָ��Ԥ����
}

//�������
inline void addLeft(int x, int pos) { 
    a[x].R = pos;
    a[a[pos].L].R = x;
    a[x].L = a[pos].L;
    a[pos].L = x;
}

//ɾ��
inline void del(int x) {
    if (a[x].L == -1) return;
    a[a[x].L].R = a[x].R;
    a[a[x].R].L = a[x].L;
    a[x].L = -1;
    a[x].R = -1;
}

//�������
inline void go() {
    int x = a[0].R;
    while (1) {
        cout << x << " ";
        if (a[x].R == -1) break;
        x = a[x].R;
    }
}

//��ʼ������
inline void init() {
    for (int i = 1; i <= n; ++i) a[i].L = a[i].R = -1;
    a[1].R = -1; a[1].L = 0; a[0].R = 1;
}

//˫�����ʾ

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