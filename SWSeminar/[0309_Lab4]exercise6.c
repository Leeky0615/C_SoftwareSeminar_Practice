#include <stdio.h>
#include <math.h>


int main(void) {

	const double money = 1000000;
	const double rate = 0.045;
	double total;
	int year;

	printf("��ġ�Ⱓ(��):");
	scanf("%d", &year);

	total = money * pow(1 + rate, year);
	printf("�� ���ɾ�(����) : %.f��\n", total);


	return 0;
}