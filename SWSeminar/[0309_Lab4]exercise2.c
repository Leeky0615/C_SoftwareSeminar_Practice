#include <stdio.h>

int main(void) {

	const double yearTosec = 3.156e7;
	int age;

	printf("����: ");
	scanf("%d", &age);

	printf("����: %d��(%e��)\n", age, age * yearTosec);


	return 0;
}