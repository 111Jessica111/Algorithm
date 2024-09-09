#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char c;
	char str[100];
	int i = 0;
	scanf("%c", &c);
	while (c != 'Z') {
		str[i] = c;
		i++;
		scanf("%c", &c);		
	}
	getchar();
	int length;
	length = i;
	//printf("%d", length);
	for (i = 0; i < length;) {
		switch (str[i])
		{
		case '0':
			switch (str[i+1])
			{
			case '0':printf("c"); i = i + 3; break;
			case '1':printf("b"); i = i + 2; break;
			default:
				break;
			}
			break;
		case '1':printf("a"); i = i + 1; break;
		default:
			break;
		}
	}
	return 0;
}