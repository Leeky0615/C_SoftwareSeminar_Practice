#include <stdio.h>

#define MAX_Rect 5

typedef struct point {
	int x, y;
}POINT;

typedef struct rect {
	POINT lt,rb;
}RECT;

void rectInfo(RECT rect);

int main(void) {
	RECT rects[MAX_Rect];

	printf("%d 개의 사각형 정보를 입력하세요.\n", MAX_Rect);

	for (size_t i = 0; i < MAX_Rect; i++)
	{
		printf("좌상단 좌표 : ");
		scanf("%d %d", &rects[i].lt.x, &rects[i].lt.y);

		printf("우하단 좌표 : ");
		scanf("%d %d", &rects[i].rb.x, &rects[i].rb.y);

		rectInfo(rects[i]);

		printf("===================================\n");
	}
	return 0;
}

void rectInfo(RECT rect) {
	int area, width,height;
	int lt_x = rect.lt.x;
	int lt_y = rect.lt.y;
	int rb_x = rect.rb.x;
	int rb_y = rect.rb.y;
	width = rb_x - lt_x;
	height = rb_y - lt_y;
	area = width * height;
	printf("============사각형 정보=============\n");
	printf("사각형 좌표 : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", lt_x,lt_y,rb_x,lt_y,rb_x,rb_y,lt_x,rb_y);
	printf("사각형 가로 : %d\n", width);
	printf("사각형 세로 : %d\n", height);
	printf("사각형 넓이 : %d\n", area);
}
