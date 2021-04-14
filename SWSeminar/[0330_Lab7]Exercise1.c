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

	printf("%d ���� �簢�� ������ �Է��ϼ���.\n", MAX_Rect);

	for (size_t i = 0; i < MAX_Rect; i++)
	{
		printf("�»�� ��ǥ : ");
		scanf("%d %d", &rects[i].lt.x, &rects[i].lt.y);

		printf("���ϴ� ��ǥ : ");
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
	printf("============�簢�� ����=============\n");
	printf("�簢�� ��ǥ : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", lt_x,lt_y,rb_x,lt_y,rb_x,rb_y,lt_x,rb_y);
	printf("�簢�� ���� : %d\n", width);
	printf("�簢�� ���� : %d\n", height);
	printf("�簢�� ���� : %d\n", area);
}
