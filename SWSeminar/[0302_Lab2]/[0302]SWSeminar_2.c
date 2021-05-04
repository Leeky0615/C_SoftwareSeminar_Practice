/* [0302]SWSeminar */
#include <stdio.h>

int main(void) {
	
	float num; // 실수형 변수 선언
	int i_part; // 정수형 변수 선언
	float f_part; // 실수형 변수 선언

	printf("실수를 입력하세요 : ");
	scanf_s("%f", &num);


	i_part = num;
	f_part = num - i_part;

	printf("%f의 정수부는 %d이고, 실수부는 %f입니다.\n", num, i_part, f_part);

	return 0;
}