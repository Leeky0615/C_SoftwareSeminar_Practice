#include <stdio.h>


int main(void) {

	const double rate = 1138.50;
	double dollar, won, total;
	int opt, year;
	
	printf("1 : ���� ȯ�� ���\n");
	printf("2 : ��ȭ�� �޷�ȭ�� ��ȯ\n");
	printf("3 : �޷��� ��ȭ�� ��ȯ\n");
	printf("�޴��� �����ϼ���:\n");
	scanf("%d", &opt);

	if (opt == 1){
		printf("���� ȯ�� : %.2f", rate);
	}
	else if (opt == 2) {
		printf("��ȭ�� �Է��ϼ���: ");
		scanf("%d", &won);
		
		dollar = won / rate;
		printf("�޷� : %.2f", dollar);
	}
	else if(opt == 3){
		printf("�޷��� �Է��ϼ���: ");
		scanf("%d", &dollar);
		won = dollar * rate;
		printf("�޷� : %lf", won);


	}
	
	

	return 0;
}