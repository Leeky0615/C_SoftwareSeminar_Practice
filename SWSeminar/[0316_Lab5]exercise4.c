#include <stdio.h>

int main(void) {
	int result = 0;

	for (size_t i = 1; i < 101; i++)
	{
		if (i % 7 == 0) {
			continue;
		}
		else {
			result  += i;
		}
	}

	printf("%d", result);
	return 0;
}