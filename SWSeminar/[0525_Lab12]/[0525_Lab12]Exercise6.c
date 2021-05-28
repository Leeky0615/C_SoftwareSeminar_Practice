#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct rect {
    int left;
    int right;
    int top;
    int bottom;
} RECT;

void PrintRect(const RECT *rect);
int Width(const RECT *rect);
int Height(const RECT *rect);
int Area(const RECT *rect);
int Perimeter(const RECT *rect);

int main(int argc, char *argv[]) {
    RECT rect = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};
    PrintRect(&rect);
    return 0;
}

void PrintRect(const RECT *rect) {
    printf("ÁÂ»ó´ÜÁ¡ = (%d, %d)\n", rect->left, rect->top);
    printf("¿ìÇÏ´ÜÁ¡ = (%d, %d)\n", rect->right, rect->bottom);
    printf("Æø = %d\n", Width(rect));
    printf("³ôÀÌ = %d\n", Height(rect));
    printf("µÑ·¹ = %d\n", Perimeter(rect));
    printf("³ÐÀÌ = %d\n", Area(rect));
}

int Perimeter(const RECT *rect) {
    return 2 * (Width(rect) + Height(rect));
}

int Area(const RECT *rect) {
    return Width(rect) * Height(rect);
}

int Width(const RECT *rect) {
    return abs(rect->right - rect->left);
}

int Height(const RECT *rect) {
    return abs(rect->top - rect->bottom);
}
