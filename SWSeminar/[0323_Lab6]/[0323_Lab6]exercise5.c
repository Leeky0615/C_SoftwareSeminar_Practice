#include <stdio.h>
#include <string.h>


void Flip(char *p, int size);

int main(void) {
	char str[10];
	char* p = str;

	printf("���ڿ��� �Է��ϼ��� : ");

	gets(str);
	Flip(p, 10);

	return 0;
}


void Flip(char *p, int size) {
	printf("Flip : ");
	int i;
	for (i = strlen(p) -1 ; i > -1; i--)
	{
		printf("%c", p[i]);
	}
	printf("\n");
}

