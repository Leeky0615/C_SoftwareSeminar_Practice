#include <stdio.h>
#include <math.h>
#include "Rect.h"


void PrintRect(const RECT *rect){
    printf("�»���� = (%d, %d)\n", rect->left, rect->top);
    printf("���ϴ��� = (%d, %d)\n", rect->right, rect->bottom);
    printf("�� = %d\n", Width(rect));
    printf("���� = %d\n", Height(rect));
}
int Width(const RECT *rect){
    return abs(rect->right - rect->left);
}
int Height(const RECT *rect){
    return abs(rect->top - rect->bottom);
}
