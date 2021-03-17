#include <stdio.h>

int main(void) {

	int year;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &year);

	printf("%d", IsLeapYear(year));

	return 0;
}

int IsLeapYear(int year) {
	if ((year % 4 == 0) && (year % 100) || (year % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}