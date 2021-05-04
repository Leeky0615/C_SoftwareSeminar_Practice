#include <stdio.h>

int main(void) {

	int hour, min, sec, totalSec;

	printf("시, 분, 초를 입력하시오:");
	scanf("%d %d %d", &hour, &min, &sec);

	totalSec = hour * 3600 + min * 60 + sec;

	printf("%d시간 %d분 %d초는 %d초 입니다.\n", hour, min, sec, totalSec);

	printf("초를 입력하시오:");
	scanf("%d", &totalSec);

	hour = totalSec / 3600;
	min = (totalSec - hour * 3600) / 60;
	sec = totalSec - (hour * 3600 + min * 60);

	printf("%d초는 %d시간 %d분 %d초입니다.\n", totalSec,hour, min, sec);

	return 0;
}