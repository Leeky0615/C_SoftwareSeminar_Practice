#include <stdio.h>
#include <math.h>


int main(void) {

	const double money = 1000000;
	const double rate = 0.045;
	double total;
	int year;

	printf("예치기간(년):");
	scanf("%d", &year);

	total = money * pow(1 + rate, year);
	printf("총 수령액(복리) : %.f원\n", total);


	return 0;
}