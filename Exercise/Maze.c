#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int flag = 0;

void out(char A[500][500], int s_x, int s_y, int x, int y) {
    int i, j;
    i = s_x;
    j = s_y;
    A[s_x][s_y] = 'x';
    if ((i - 1) >= 0 && A[i - 1][j] != 'x') {
        if (A[i - 1][j] == 't') flag = 1;
        else
            out(A, i - 1, j, x, y);
    }
    if ((j - 1) >= 0 && A[i][j - 1] != 'x') {
        if (A[i - 1][j] == 't') flag = 1;
        else
            out(A, i, j - 1, x, y);
    }
    if ((j + 1) < y && A[i][j + 1] != 'x') {
        if (A[i][j + 1] == 't') flag = 1;
        else
            out(A, i, j + 1, x, y);
    }
    if ((i + 1) < x && A[i + 1][j] != 'x') {
        if (A[i - 1][j] == 't') flag = 1;
        else
            out(A, i + 1, j, x, y);
    }
}

int check_out(int A[500][500], int s_x, int s_y, int x, int y) {
    out(A, s_x, s_y, x, y);
    if (flag == 1) return 1;
    else return 0;
}

int main() {
    int n;
    int x, y;
    int i, j, k;
    int s_x, s_y;
    char A[500][500];
    char c;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    getchar();
    for (k = 0; k < n; k++) {
        for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++) {
                scanf("%c", &c);
                A[i][j] = c;
                getchar();
            }
        }
        for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++) {
                if (A[i][j] == 's') {
                    s_x = i;
                    s_y = j;
                    goto a;
                }
            }
        }
        a:
        //printf("%d %d", s_x, s_y);
        if (check_out(A, s_x, s_y, x, y)) printf("Yes");
        else {
            printf("No");
        }
    }
    //for (i = 0; i < x; i++) {
    //    for (j = 0; j < y; j++) {
    //        printf("%c ", A[i][j]);
    //    }
    //    printf("\n");
    //}
    return 0;
}