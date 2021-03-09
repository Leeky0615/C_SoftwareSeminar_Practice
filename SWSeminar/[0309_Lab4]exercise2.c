#include <stdio.h>

int main(void) {

	const double yearTosec = 3.156e7;
	int age;

	printf("나이: ");
	scanf("%d", &age);

	printf("나이: %d세(%e초)\n", age, age * yearTosec);


	return 0;
}