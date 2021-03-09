#include <stdio.h>


int main(void) {

	const double rate = 1138.50;
	double dollar, won, total;
	int opt, year;
	
	printf("1 : 기준 환율 출력\n");
	printf("2 : 원화를 달러화로 변환\n");
	printf("3 : 달러를 원화로 변환\n");
	printf("메뉴를 선택하세요:\n");
	scanf("%d", &opt);

	if (opt == 1){
		printf("기준 환율 : %.2f", rate);
	}
	else if (opt == 2) {
		printf("원화를 입력하세요: ");
		scanf("%d", &won);
		
		dollar = won / rate;
		printf("달러 : %.2f", dollar);
	}
	else if(opt == 3){
		printf("달러를 입력하세요: ");
		scanf("%d", &dollar);
		won = dollar * rate;
		printf("달러 : %lf", won);


	}
	
	

	return 0;
}