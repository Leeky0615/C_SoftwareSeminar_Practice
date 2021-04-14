#include <stdio.h>
#include <math.h>

typedef struct point {
	int x, y;
}POINT;

typedef struct line {
	POINT start, end;
}LINE;

double cal_lengh(struct point* start, struct point* end);

int main(void) {
	LINE line;
	struct LINE* p = &line;
	double lengh;

	printf("시작점 좌표 : ");
	scanf("%d %d", &line.start.x, &line.start.y);
	
	printf("끝점 좌표 : ");
	scanf("%d %d", &line.end.x, &line.end.y);

	lengh = cal_lengh(&line.start, &line.end);
	printf("직선의 거리 : %.2f\n", lengh);

	return 0;
}


double cal_lengh(struct point* start, struct point* end){
	return sqrt(pow((start->x-end->x),2) + pow((start->y - end->y), 2));
}