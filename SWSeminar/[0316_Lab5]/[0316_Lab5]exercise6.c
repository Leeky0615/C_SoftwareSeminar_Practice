#include <stdio.h>

int g_result;
void plusValue(int num);
void minusValue(int num);

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
		case '-':
			minusValue(num);
			break;
		case '+':
			plusValue(num);
			break;
		default:
			break;
;		}

	}
		
	printf("%d\n", g_result);

	return 0;
}
void plusValue(int num) {
	g_result+=num;

}

void minusValue(int num) {
	g_result-=num;
}