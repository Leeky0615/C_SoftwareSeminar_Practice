#include <stdio.h>
#include <stdbool.h>

int main(void) {

	const double rate = 1138.50;
	float dollar, won, total;
	int opt;
	bool state = false;

	while (!state) {
		printf("=========================\n");
		printf("1 : ���� ȯ�� ���\n");
		printf("2 : ��ȭ�� �޷�ȭ�� ��ȯ\n");
		printf("3 : �޷��� ��ȭ�� ��ȯ\n");
		printf("4 : ����\n");
		printf("�޴��� �����ϼ���:");
		scanf("%d", &opt);
		printf("\n=  =  =  =  =  =  =  =  =\n");

		if (opt == 1) {
			printf("\n[1 : ���� ȯ�� ���]\n");
			printf("���� ȯ�� : %.2f\n\n", rate);
		}else if (opt == 2) {
			printf("\n[2 : ��ȭ�� �޷�ȭ�� ��ȯ]\n");

			printf("��ȭ�� �Է��ϼ���: ");
			scanf("%f", &won);

			dollar = won / rate;

			printf("�޷� : %.2f�޷�\n\n", dollar);
		}else if (opt == 3) {
			printf("\n[3 : �޷��� ��ȭ�� ��ȯ]\n");

			printf("�޷��� �Է��ϼ���: ");
			scanf("%f", &dollar);

			won = dollar*rate;

			printf("��ȭ : %.f��\n\n", won);
		}else {
			printf("\n�����մϴ�.\n");
			state = true;
		}
	}
	return 0;
}