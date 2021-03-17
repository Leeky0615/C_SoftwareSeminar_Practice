#include <stdio.h>

int g_result;
void plusValue(int num);
void minusValue(int num);
void printResult(void);

int main(void) {
	int num;
	char cal;
	g_result = 0;

	printf("원하는 연산(+ 혹은 -)와 정수값을 입력하세요.\n");
	printf("더 이상 입력하지 않고자 할 때는 0을 입력하세요.\n");
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