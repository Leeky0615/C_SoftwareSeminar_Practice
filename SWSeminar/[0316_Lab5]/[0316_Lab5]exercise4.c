#include <stdio.h>

int main(void) {
	int result = 0;
	int index;

	for (size_t i = 1; i < 101; i++)
	{
		if (i % 7 == 0) {
			continue;
		}
		else {
			result += i;
		}
	}
	printf("For�� : %d\n", result);

	result = 0;
	index = 0;
	while (index < 100) {
		index++;
		if (index % 7 == 0) {
			continue;
		}
		else {
			result += index;
		}
	}
	printf("while�� : %d\n", result);

	result = 0;
	index = 0;
	do
	{
		index++;
		if (index % 7 == 0) {
			continue;
		}
		else {
			result += index;
		}
	} while (index < 100);
	

	printf("do_While�� : %d\n", result);

	return 0;
}