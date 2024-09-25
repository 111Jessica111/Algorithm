#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check_right(int i, int num1, int num2) {
    int B[9] = { 0,0,0,0,0,0,0,0,0 };
    int x;
    int j;
    for (x = 0; x < 3; x++) {
        j = i % 10;
        if (B[j - 1] == 0) {
            B[j - 1] = 1;
            i = i / 10;
        }
        else {
            return 0;
        }
    }
    for (x = 0; x < 3; x++) {
        j = num1 % 10;
        if (B[j - 1] == 0) {
            B[j - 1] = 1;
            num1 = num1 / 10;
        }
        else {
            return 0;
        }
    }
    for (x = 0; x < 3; x++) {
        j = num2 % 10;
        if (B[j - 1] == 0) {
            B[j - 1] = 1;
            num2 = num2 / 10;
        }
        else {
            return 0;
        }
    }
    return 1;
}

int main_30() {
    int i;
    int num1, num2;
    for (i = 123; i <= 333; i++) {
        num1 = i * 2;
        num2 = i * 3;
        if (check_right(i, num1, num2)) {
            printf("%d %d %d\n", i, num1, num2);
        }
    }
    return 0;
}