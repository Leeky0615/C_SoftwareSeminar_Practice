#include <stdio.h>


int main(void) {
    int a = 1, b = 2, c = 3;
    int result;

    result = a + b * c % 2;
    // result = (1 + (2x3)) % 2 = 1
    printf("result = %d\n", result);

    result = a > b || c > 0;
    // result = 0 || 1 = 1
    printf("result = %d\n", result);

    result = a > b || c > 0 && b > c;
    // result = 0 || 1 && 0 = 0
    printf("result = %d\n", result);

    result = ++a * b--;
    // result = 2 x 2 = 4
    printf("result = %d\n", result);

    result = a = b = c;
    // result = 3
    printf("result = %d\n", result);

    return 0;

}