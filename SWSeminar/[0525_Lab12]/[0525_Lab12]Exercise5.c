#include <stdio.h>

typedef unsigned char BYTE;
#define MAKE_RGB(r, g, b)((BYTE)(r)<< 16) | ((BYTE)(g) << 8) | (BYTE)(b)
#define GET_RED(color)(BYTE)((color)>> 16)
#define GET_GREEN(color)(BYTE)((color)>> 8)
#define GET_BLUE(color)(BYTE)(color)


int main() {
    int color = MAKE_RGB(0xA4, 0xE3, 0xF4);
    printf("%X\n", color);
    printf("R = %d : G = %d : B = %d\n", GET_RED(color), GET_GREEN(color), GET_BLUE(color));
    return 0;
}