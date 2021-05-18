#include <stdio.h>
#include <math.h>
#include "Rect.h"


void PrintRect(const RECT *rect){
    printf("좌상단점 = (%d, %d)\n", rect->left, rect->top);
    printf("우하단점 = (%d, %d)\n", rect->right, rect->bottom);
    printf("폭 = %d\n", Width(rect));
    printf("높이 = %d\n", Height(rect));
}
int Width(const RECT *rect){
    return abs(rect->right - rect->left);
}
int Height(const RECT *rect){
    return abs(rect->top - rect->bottom);
}
