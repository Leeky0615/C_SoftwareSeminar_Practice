#include <stdio.h>

int main(void) {
	double c, f;


	printf("�µ�(����)�� �Է��ϼ���: ");
	scanf("%lf", &c);

	f = 9.0 / 5.0 * c + 32.0;

	printf("���� %.2f�� -> ȭ�� %.2f��.\n", c, f);

	return 0;
}