#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;
	for (a = 0; a <= 1; a++) {
		for (b = 0; b <= 1; b++) {
			for (c = 0; c <= 1; ) {
				if (((a == 1 && b == 0) || (a == 0 && b == 1)) && ((b == 1 && c == 0) || (b == 0 && c == 1)) && ((c == 1 && (a + b) == 0) || (c == 0 && (a + b) != 0))) {
					printf("A told a %s\n", a ? "truth" : "lie");
					printf("B told a %s\n", b ? "truth" : "lie");
					printf("C told a %s\n", c ? "truth" : "lie");
				}
				c++;
			}
		}
	}
	return 0;
}
//(((a == 1 && b == 0) || (a == 0 && b == 1)) && ((b == 1 && c == 0) || (b == 0 && c == 1)) && ((c == 1 && (a + b) == 0) || (c == 0 && (a + b) != 0))) 
//(((a && !b) || (!a && b)) && ((b && !c) || (!b && c)) && ((c && !(a + b)) || (!c && (a + b)))) 