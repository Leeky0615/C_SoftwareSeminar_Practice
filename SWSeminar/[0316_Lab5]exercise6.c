#include <stdio.h>

int g_result;
void plusValue(int num);
void minusValue(int num);
void printResult(void);

int main(void) {
	int num;
	char cal;
	g_result = 0;

	printf("���ϴ� ����(+ Ȥ�� -)�� �������� �Է��ϼ���.\n");
	printf("�� �̻� �Է����� �ʰ��� �� ���� 0�� �Է��ϼ���.\n");
	while (1) {
		scanf("%c", &cal);
		if (cal == '0') {
			break;
		}
		scanf("%d", &num);
		getchar();


		switch(cal){
		case '+':
			plusValue(num);
		case '-':
			minusValue(num);
;		}

	}
		
	printResult();


	return 0;
}
void printResult(void) {
	printf("%d", g_result);
}
void plusValue(int num) {
	g_result = g_result + num;
}

void minusValue(int num) {
	g_result = g_result - num;
}