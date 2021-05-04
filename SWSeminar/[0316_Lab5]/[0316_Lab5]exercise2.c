#include <stdio.h>

int main(void) {

	char result = 'A';

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < i + 1; j++)
		{
			printf("%c",result);
			result++;
		}
		result = 'A';
		printf("\n");
	}


	return 0;
}