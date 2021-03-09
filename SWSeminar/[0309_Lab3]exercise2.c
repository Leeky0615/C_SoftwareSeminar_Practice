#include <stdio.h>

int main(void) {

	char ch;

	printf("문자를 입력하세요 : ");

	scanf("%c", &ch);

	printf("%c 문자의 ASCII코드 : %d (%x)\n", ch, ch, ch);

	return 0;
}