#include<stdio.h>
typedef enum week {
	sun,
	mon,
	tue,
	wed,
	thu,
	fri,
	sat,
	week_Count
}WEEK;

int main(void) {

	for (WEEK i = sun; i < week_Count; i++)
	{
		printf("����ü�� ���� ����� : %d\n", i);
	}
	return 0;
}
