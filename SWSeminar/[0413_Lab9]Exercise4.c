#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct contact {
	char name[20];
	char phone[15];
}CONTACT;

int main(void) {
	CONTACT* cont[100] = { NULL };

	
	while (1) {
		char nameToSearch[20];

		bool exitOuterLoop = false;
		printf("�˻��� �̸� : ");
		scanf("%s", nameToSearch);
		//gets_s(nameToSearch, sizeof(nameToSearch));
		if (nameToSearch == ".") {
			break;
		}

		int lastContactNum = 0;
		for (size_t i = 0; i<100; i++)
		{
			if (i == lastContactNum) {
				break;
			}
			else if (cont[i]->name == nameToSearch) {
				printf("ã�� ��ȭ��ȣ : %s\n", cont[i]->phone);
				exitOuterLoop = true;
			}
		}
		if (exitOuterLoop) {
			break;
		}
		else
		{
			char saveOpt;
			printf("������� ���� ����ó�Դϴ�. �����Ͻðڽ��ϱ�? (Y/N) : ");
			//char saveOpt = getchar();
			scanf("%c", &saveOpt);
			fflush(stdin);

			if (saveOpt == 'y' || saveOpt == 'Y') {
				char phoneToSave[15];

				printf("��ȭ��ȣ �Է� : ");
				//gets_s(phoneToSave, sizeof(phoneToSave));

				scanf("%s", phoneToSave);
				cont[lastContactNum] = malloc(sizeof(CONTACT));
				strcpy(cont[lastContactNum]->name, nameToSearch);
				strcpy(cont[lastContactNum]->phone, phoneToSave);
				lastContactNum++;
				fflush(stdin);
			}
			else {
				continue;
			}
		
		}
		/*
		
		for (size_t i = 0; i < lastContactNum; i++)
		{
			free(cont[i]);
			cont[i] = NULL;
		}
		*/
		printf("\n");
	}

	return 0;
}