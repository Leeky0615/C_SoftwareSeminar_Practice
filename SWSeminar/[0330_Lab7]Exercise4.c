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
	printf("���簢���� �̷� �� �ִ� �� ���� �Է��ϼ���\n");
	printf("��ǥ1 : ");
	scanf("%d %d", &rect_p1.x, &rect_p1.y);

	printf("��ǥ2 : ");
	scanf("%d %d", &rect_p2.x, &rect_p2.y);

	rect.lt = rect_p1;
	rect.rb = rect_p2;

	rect = normalizeRect(rect); // �簢�� ����ȭ
	printRect(rect); // �簢�� ���� ���
	printf("Ȯ�� �ϰ��� �ϴ� ��ǥ : ");
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
		printf("�ش� ��ǥ�� �簢�� �ȿ� �ֽ��ϴ�.\n");
	}
	else {
		printf("�ش� ��ǥ�� �簢�� �ȿ� �����ϴ�.\n");
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
	printf("============�簢�� ����=============\n");
	printf("�簢�� ��ǥ : (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", lt_x, lt_y, rb_x, lt_y, rb_x, rb_y, lt_x, rb_y);
	printf("�簢�� ���� : %d\n", width);
	printf("�簢�� ���� : %d\n", height);
	printf("�簢�� ���� : %d\n", area);
}