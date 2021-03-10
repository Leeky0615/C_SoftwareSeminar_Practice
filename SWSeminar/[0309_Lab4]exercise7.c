#include <stdio.h>
#include <stdbool.h>

int main(void) {

	const double rate = 1138.50;
	float dollar, won, total;
	int opt;
	bool state = false;

	while (!state) {
		printf("=========================\n");
		printf("1 : 기준 환율 출력\n");
		printf("2 : 원화를 달러화로 변환\n");
		printf("3 : 달러를 원화로 변환\n");
		printf("4 : 종료\n");
		printf("메뉴를 선택하세요:");
		scanf("%d", &opt);
		printf("\n=  =  =  =  =  =  =  =  =\n");

		if (opt == 1) {
			printf("\n[1 : 기준 환율 출력]\n");
			printf("기준 환율 : %.2f\n\n", rate);
		}else if (opt == 2) {
			printf("\n[2 : 원화를 달러화로 변환]\n");

			printf("원화를 입력하세요: ");
			scanf("%f", &won);

			dollar = won / rate;

			printf("달러 : %.2f달러\n\n", dollar);
		}else if (opt == 3) {
			printf("\n[3 : 달러를 원화로 변환]\n");

			printf("달러를 입력하세요: ");
			scanf("%f", &dollar);

			won = dollar*rate;

			printf("원화 : %.f원\n\n", won);
		}else {
			printf("\n종료합니다.\n");
			state = true;
		}
	}
	return 0;
}