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
		printf("열거체의 열거 상수값 : %d\n", i);
	}
	return 0;
}
