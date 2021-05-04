#include <stdio.h>
#include <string.h>

void MakeLower(char str[], int size);
void MakeUpper(char str[], int size);

int main(void) {
	char str1[10], str2[10];

	printf("문자열을 입력하세요 : ");

	strcpy(str1, gets(str2));

	MakeLower(str1, 10);
	MakeUpper(str2, 10);

	return 0;
}


void MakeLower(char str[], int size) {
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
		else if (str[i] == '\0') {
			break;
		}
	}
	printf("MakeLower : %s\n", str);
;}

void MakeUpper(char str[], int size) {
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 32;
		}
		else if (str[i] == '\0') {
			break;
		}
	}
	printf("MakeUpper : %s\n", str);
}