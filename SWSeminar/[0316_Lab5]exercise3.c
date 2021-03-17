#include <stdio.h>

int main(void) {

	char result;

	printf("문자를 입력하세요 : ");
	scanf("%c", &result);

	for (size_t i = 0; i < 7; i++)
	{
		for (size_t k = 0; k < 6-i; k++)
		{
			printf(" ");
		}
		for (size_t j = 0; j < (i*2) + 1; j++)
		{
			printf("%c", result);
		}
		printf("\n");
	}


	return 0;
}