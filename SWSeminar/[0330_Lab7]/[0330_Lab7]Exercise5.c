#include <stdio.h>
#include <math.h>

typedef struct point {
	int x, y;
}POINT;

typedef struct rect {
	POINT lt, rb;
}RECT;

RECT InputRect(POINT p1, POINT p2);
POINT centerOfRect(RECT rect);

int main(void) {
	POINT rect_p1, rect_p2, point;

	printf("직사각형을 이룰 수 있는 두 점을 입력하세요\n");
	printf("좌표1 : ");
	scanf("%d %d", &rect_p1.x, &rect_p1.y);

	printf("좌표2 : ");
	scanf("%d %d", &rect_p2.x, &rect_p2.y);


	point = centerOfRect(InputRect(rect_p1, rect_p2));
	printf("사각형의 중심점 : (%d, %d)\n", point.x, point.y);


	return 0;
}

RECT InputRect(POINT p1, POINT p2) {
	RECT rect;
	double lengh_p1 = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
	double lengh_p2 = sqrt(pow(p2.x, 2) + pow(p2.y, 2));
	if (lengh_p1 < lengh_p2) {
		rect.lt = p1;
		rect.rb = p2;
	}
	else if (lengh_p1 > lengh_p2) {
		rect.lt = p2;
		rect.rb = p1;
	}

	return rect;
}

POINT centerOfRect(RECT rect) {
	POINT  point;
	point.x = (rect.rb.x + rect.lt.x) / 2;
	point.y = (rect.rb.y + rect.lt.y) / 2;
	return point;
}
