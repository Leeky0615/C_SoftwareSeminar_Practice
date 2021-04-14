#include <stdio.h>
#include <math.h>

typedef struct point {
	int x, y;
}POINT;

typedef struct rect {
	POINT lt, rb;
}RECT;

RECT normalizeRect(RECT rect);
void isPointInRect(RECT rect, POINT point);
void printRect(RECT rect);

int main(void) {
	RECT rect;
	POINT rect_p1, rect_p2, point;
	printf("직사각형을 이룰 수 있는 두 점을 입력하세요\n");
	printf("좌표1 : ");
	scanf("%d %d", &rect_p1.x, &rect_p1.y);

	printf("좌표2 : ");
	scanf("%d %d", &rect_p2.x, &rect_p2.y);

	rect.lt = rect_p1;
	rect.rb = rect_p2;

	rect = normalizeRect(rect); // 사각형 정규화
	printRect(rect); // 사각형 정보 출력
	printf("확인 하고자 하는 좌표 : ");
	scanf("%d %d", &point.x, &point.y);

	isPointInRect(rect, point);

	return 0;
}

RECT normalizeRect(RECT rect) {
	POINT p1 = rect.lt;
	POINT p2 = rect.rb;
	RECT normalized_Rect;
	double lengh_p1 = sqrt(pow(p1.x, 2) + pow(p1.y, 2));
	double lengh_p2 = sqrt(pow(p2.x, 2) + pow(p2.y, 2));
	if (lengh_p1 < lengh_p2) {
		normalized_Rect.lt = p1;
		normalized_Rect.rb = p2;
	}
	else if (lengh_p1 > lengh_p2) {
		normalized_Rect.lt = p2;
		normalized_Rect.rb = p1;
	}

	return normalized_Rect;
}

void isPointInRect(RECT rect, POINT point) {
	if ((rect.lt.x < point.x) && (rect.lt.y < point.y) && (rect.rb.x > point.x) && (rect.rb.y > point.y)) {
		printf("해당 좌표는 사각형 안에 있습니다.\n");
	}
	else {
		printf("해당 좌표는 사각형 안에 없습니다.\n");
	}
}

void printRect(RECT rect) {
	int area, width, height;
	int lt_x = rect.lt.x;
	int lt_y = rect.lt.y;
	int rb_x = rect.rb.x;
	int rb_y = rect.rb.y;
	width = rb_x - lt_x;
	height = rb_y - lt_y;
	area = width * height;
	printf("============사각형 정보=============\n");
	printf("사각형 좌표 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", lt_x, lt_y, rb_x, lt_y, rb_x, rb_y, lt_x, rb_y);
	printf("사각형 가로 : %d\n", width);
	printf("사각형 세로 : %d\n", height);
	printf("사각형 넓이 : %d\n", area);
}