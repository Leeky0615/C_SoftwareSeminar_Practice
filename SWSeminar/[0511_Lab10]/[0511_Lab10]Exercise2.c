#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 32

typedef struct contact {
    char name[MAX];
    char phone[MAX];
} CONTACT;

CONTACT *AllocateContacts(int count);
void InputContacts(CONTACT *contacts, int count);
void PrintContacts(const CONTACT *contacts, int count);
int CompareByName(const void *e1, const void *e2);
int CompareByPhone(const void *e1, const void *e2);

int main(void) {
    CONTACT *contacts = NULL;
    int cnt = 0;

    printf("������ ����ó�� ���� : ");
    scanf("%d", &cnt);
    while (getchar() != '\n');

    contacts = AllocateContacts(cnt);
    if (contacts == NULL) return -1;

    InputContacts(contacts, cnt);

    while (1) {
        int opt;
        printf("\n0. ����\n");
        printf("1. �̸��� ���\n");
        printf("2. ��ȭ��ȣ�� ���\n");

        printf("��¹�� ���� : ");
        scanf("%d", &opt);
        if(opt == 0) break;
        else if(opt == 1) qsort(contacts, cnt, sizeof(CONTACT), CompareByName);
        else if(opt == 2) qsort(contacts, cnt, sizeof(CONTACT), CompareByPhone);
        PrintContacts(contacts, cnt);
    }

    free(contacts);
    contacts = NULL;

    return 0;
}

CONTACT *AllocateContacts(int count) {
    CONTACT *result = NULL;
    result = (CONTACT *) malloc(sizeof(CONTACT) * count);
    if (result == NULL) printf("���� �޸� �Ҵ� ����\n");
    else memset(result, 0, sizeof(CONTACT) * count);
    return result;
}

void InputContacts(CONTACT *contacts, int count) {
    for (int i = 0; i < count; i++) {
        printf("��   �� : ");
        gets_s(contacts[i].name,MAX);

        printf("��ȭ��ȣ : ");
        gets_s(contacts[i].phone,MAX);
    }
}

void PrintContacts(const CONTACT* contacts, int count){
    printf("\n--- ��ü ����ó ��� ---\n");
    for(int i = 0; i < count; i++ ){
        printf("%-16s %-16s\n", contacts[i].name, contacts[i].phone);
    }
}
int CompareByName(const void *e1, const void *e2){
    const CONTACT *p1 = (const CONTACT *) e1;
    const CONTACT *p2 = (const CONTACT *) e2;
    return strcmp(p1->name, p2->name);
}
int CompareByPhone(const void *e1, const void *e2){
    const CONTACT *p1 = (const CONTACT *) e1;
    const CONTACT *p2 = (const CONTACT *) e2;
    return  strcmp(p1->phone, p2->phone);
}
