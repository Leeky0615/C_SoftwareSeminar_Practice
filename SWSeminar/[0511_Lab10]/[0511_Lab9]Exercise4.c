#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct contact {
    char name[32];
    char phone[32];
} CONTACT;

int main() {
    CONTACT *contacts[MAX] = {NULL};
    int cnt = 0;
    char nameToFind[32];
    int found;
    while (1) {
        printf("�˻��� �̸� : ");
        gets(nameToFind);

        if (strcmp(nameToFind, ".") == 0) break;

        found = -1;
        for (int i = 0; i < cnt; i++) {
            if (strcmp(nameToFind, contacts[i]->name) == 0) {
                found = i;
                break;
            }
        }
        if (found == -1) {
            if (cnt < MAX) {
                char opt;
                printf("������� ���� ����ó�Դϴ�. �����Ͻðڽ��ϱ�? (Y/N): ");
                scanf("%c", &opt);
                while (getchar() != '\n');

                if (opt == 'Y' || opt == 'y') {
                    contacts[cnt] = (CONTACT *) malloc(sizeof(CONTACT));
                    memset(contacts[cnt], 0, sizeof(CONTACT));
                    strcpy(contacts[cnt]->name, nameToFind);
                    printf("��ȭ��ȣ �Է� : ");
                    gets(contacts[cnt]->phone);
                    cnt++;
                } else continue;
            } else printf("�� �̻� ����ó�� ������ �� �����ϴ�.\n");
        } else {
            printf("ã�� ��ȭ��ȣ : ");
            puts(contacts[found]->phone);
        }
        printf("\n");
    }

    for (int i = 0; i < cnt; i++) {
        free(contacts[i]);
        contacts[i] = NULL;
    }

    return 0;
}