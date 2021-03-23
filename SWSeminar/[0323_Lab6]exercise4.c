#include <stdio.h>
#include <string.h>


void Encrypt(char str[], int size);

int main(void) {
	char str[10];

	printf("문자열을 입력하세요 : ");

	gets(str);

	Encrypt(str, 10);

	return 0;
}


void Encrypt(char str[], int size) {
	for (size_t i = 0; i < size; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			if (str[i] == 'Z' || str[i] == 'z') {
				str[i] -= 25;
			}
			else {
				str[i] += 1;
			}
		}
		else if (str[i] == '\0') {
			break;
		}
	}
	printf("Encrypt : %s\n", str);
}

