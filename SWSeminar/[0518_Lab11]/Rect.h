#ifndef RECT_H
#define RECT_H

typedef struct point{
    int x;
    int y;
}POINT;

typedef struct rect{
    int left;
    int right;
    int top;
    int bottom;
}RECT;

void PrintRect(const RECT *rect);
int Width(const RECT *rect);
int Height(const RECT *rect);

#endif;
