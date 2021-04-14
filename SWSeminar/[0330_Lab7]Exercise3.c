#include <stdio.h>
#include <math.h>

typedef struct point {
	int x, y;
}POINT;

typedef struct rect {
	POINT lt, rb;
}RECT;

RECT checkRect(POINT p1, POINT p2);
void checkPoint(RECT rect, POINT point);

int main(void) {
	RECT rect;
	POINT rect_p1, rect_p2, point;
	printf("직사각형을 이룰 수 있는 두 점을 입력하세요\n");
	printf("좌표1 : ");
	scanf("%d %d", &rect_p1.x, &rect_p1.y);

	printf("좌표2 : ");
	scanf("%d %d", &rect_p2.x, &rect_p2.y);

	rect = checkRect(rect_p1, rect_p2);

	printf("확인 하고자 하는 좌표 : ");
	scanf("%d %d", &point.x, &point.y);

	checkPoint(rect, point);

	return 0;
}

RECT checkRect(POINT p1, POINT p2) {
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

void checkPoint(RECT rect, POINT point) {
	if ((rect.lt.x < point.x) && (rect.lt.y < point.y) && (rect.rb.x > point.x) && (rect.rb.y > point.y)) {
		printf("해당 좌표는 사각형 안에 있습니다.\n");
	}
	else {
		printf("해당 좌표는 사각형 안에 없습니다.\n");
	}
}
