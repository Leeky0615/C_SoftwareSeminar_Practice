#include <stdio.h>

int main(void) {
	int age;
	float score;

	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d", &age);
	printf("�Է��Ͻ� ���̴� %d �Դϴ�.\n", age);

	printf("������ �Է��ϼ��� : ");
	scanf_s("%f", &score);
	printf("�Է��Ͻ� ������ %.2f �Դϴ�.\n", score);
	
	return 0;
}