#include <stdio.h>

int main(void) {

	int hour, min, sec, totalSec;

	printf("��, ��, �ʸ� �Է��Ͻÿ�:");
	scanf("%d %d %d", &hour, &min, &sec);

	totalSec = hour * 3600 + min * 60 + sec;

	printf("%d�ð� %d�� %d�ʴ� %d�� �Դϴ�.\n", hour, min, sec, totalSec);

	printf("�ʸ� �Է��Ͻÿ�:");
	scanf("%d", &totalSec);

	hour = totalSec / 3600;
	min = (totalSec - hour * 3600) / 60;
	sec = totalSec - (hour * 3600 + min * 60);

	printf("%d�ʴ� %d�ð� %d�� %d���Դϴ�.\n", totalSec,hour, min, sec);

	return 0;
}