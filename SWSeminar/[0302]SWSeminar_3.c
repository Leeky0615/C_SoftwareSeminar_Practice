#include <stdio.h>

int main(void) {
	int age;
	float score;

	printf("나이를 입력하세요 : ");
	scanf_s("%d", &age);
	printf("입력하신 나이는 %d 입니다.\n", age);

	printf("점수를 입력하세요 : ");
	scanf_s("%f", &score);
	printf("입력하신 점수는 %.2f 입니다.\n", score);
	
	return 0;
}