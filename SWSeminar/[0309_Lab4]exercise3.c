#include <stdio.h>

int main(void) {
	double c, f;


	printf("¿Âµµ(¼·¾¾)¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
	scanf("%lf", &c);

	f = 9.0 / 5.0 * c + 32.0;

	printf("¼·¾¾ %.2fµµ -> È­¾¾ %.2fµµ.\n", c, f);

	return 0;
}