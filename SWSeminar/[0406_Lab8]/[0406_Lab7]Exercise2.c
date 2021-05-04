#define MAX_NAME 20
#include<stdio.h>


 typedef struct person
{
	char name[MAX_NAME];
	int age;
	struct {
		int country_code;
		unsigned long long phone_num;
	}phone;
}PERSON;


int main(void) {
	PERSON a = {"�̱Կ�",28,{82, 1062907184}};

	PERSON b;
	strcpy(b.name, "ȫ�浿");
	b.age = 27;
	b.phone.country_code = 82;
	b.phone.phone_num = 1012345678;

	printf("�̸� : %s\n",a.name);
	printf("���� : %d��\n",a.age);
	printf("�޴���ȭ ��ȣ : %d %llu\n",a.phone.country_code, a.phone.phone_num);
	printf("===============================\n");

	printf("�̸� : %s\n",b.name);
	printf("���� : %d��\n",b.age);
	printf("�޴���ȭ ��ȣ : %d %llu\n",b.phone.country_code, b.phone.phone_num);
	return 0;
}

