#include <stdio.h>

typedef struct Student {
	int id;
	char name[100];
	float score;
}Student;

int Search(Student S[], int Search_id) {
	int i;
	for (i = 0; i < 4; i++) {
		if (S[i].id == Search_id) {
			return i;
		}
	}
	return -1;
}


int main() {
	Student S[4];
	int i;
	int Search_id;
	printf("Input student information:\n");
	for (i = 0; i < 4; i++) {
		scanf_s("%d %s %f", &S[i].id, S[i].name,sizeof(S[i].name), &S[i].score);
		//scanf_s("%d", &S[i].id);
		//scanf_s("%s", S[i].name,sizeof(S[i].name));
		//scanf_s("%f", &S[i].score);
	}
	printf("Input search id:\n");
	scanf_s("%d", &Search_id);
	i = Search(S, Search_id);
	if (i != -1) printf("%d %s %f", S[i].id, S[i].name, S[i].score);
	else printf("Can't find the student");
	return 0;
}