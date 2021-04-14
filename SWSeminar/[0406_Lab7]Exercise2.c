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
	PERSON a = {"이규연",28,{82, 1062907184}};

	PERSON b;
	strcpy(b.name, "홍길동");
	b.age = 27;
	b.phone.country_code = 82;
	b.phone.phone_num = 1012345678;

	printf("이름 : %s\n",a.name);
	printf("나이 : %d세\n",a.age);
	printf("휴대전화 번호 : %d %llu\n",a.phone.country_code, a.phone.phone_num);
	printf("===============================\n");

	printf("이름 : %s\n",b.name);
	printf("나이 : %d세\n",b.age);
	printf("휴대전화 번호 : %d %llu\n",b.phone.country_code, b.phone.phone_num);
	return 0;
}

