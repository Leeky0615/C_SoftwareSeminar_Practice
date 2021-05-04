#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdio.h>


int main(void) {
	const time_t t = time(NULL);
	struct tm* date= localtime(&t);

	printf("%d³â %d¿ù %dÀÏ\n", date->tm_year + 1900, date->tm_mon + 1, date->tm_mday);


	return 0;
}
