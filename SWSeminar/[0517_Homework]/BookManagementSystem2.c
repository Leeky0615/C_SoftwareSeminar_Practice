#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 32

typedef struct book {
    char name[MAX];
    char writer[MAX];
    unsigned int price;
} BOOK;

BOOK *AllocateBooks(int count); // �ʱ� �޸� �Ҵ�

void PrintBookInfos(const BOOK *book, int count); // ��� ���� ���� ���
void InputBooks(BOOK *books, int count); // opt=1 ���� �Է�

int CompareByPrice(const void *e1, const void *e2);

int main() {
    BOOK *books = NULL; // ����ü �迭
    int cnt = 0; // ����ü �迭 ũ��
    int opt; // �ɼ� ��ȣ
    char bookToSearch[MAX]; // �˻� �Ķ����
    bool bOnLoop = true; // opt=5 (��)
    int found;

    printf("������ ������ ���� : ");
    scanf("%d", &cnt);
    while (getchar() != '\n');

    books = AllocateBooks(cnt);
    if (books == NULL) return -1;

    printf("----���� ���� ���α׷�----\n");
    while (bOnLoop) {
        printf("1. ���� �Է�\n");
        printf("2. ���ں� �˻�\n");
        printf("3. ���� �˻�\n");
        printf("4. ���� ������ ����\n");
        printf("5. ��\n");

        printf("�޴��� �����ϼ���: ");
        scanf("%d", &opt);
        while (getchar() != '\n');
        printf("\n");
        switch (opt) {
            case 1:
                InputBooks(books, cnt);
                break;
            case 2:
                printf("-> ���ڸ� : ");
                gets_s(bookToSearch,MAX); // �˻� �Ķ����
                if (strcmp(bookToSearch, ".") == 0) break;
                found = -1;
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookToSearch, books[i].writer) == 0) {
                        found = i;
                        break;
                    }
                }
                if(found == -1) printf("��Ͽ� ���� ���ڸ��Դϴ�.");
                else{
                    printf("���� ����: %s\n", books[found].name);
                    printf("�� �� ��: %s\n", books[found].writer);
                    printf("��    �� : %d\n", books[found].price);
                }
                break;
            case 3:
                printf("-> �������� : ");
                gets_s(bookToSearch,MAX); // �˻� �Ķ����
                if (strcmp(bookToSearch, ".") == 0) break;
                found = -1;
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookToSearch, books[i].name) == 0) {
                        found = i;
                        break;
                    }
                }
                if(found == -1) printf("��Ͽ� ���� ���������Դϴ�.");
                else{
                    printf("���� ����: %s\n", books[found].name);
                    printf("�� �� ��: %s\n", books[found].writer);
                    printf("��    �� : %d\n", books[found].price);
                }
                break;
            case 4:
                qsort(books, cnt, sizeof(BOOK), CompareByPrice);
                PrintBookInfos(books, cnt);
                break;
            case 5:
                bOnLoop = false;
                break;
            default:
                printf("�ɼǿ� �´� ��ȣ�� �Է��ϼ���\n");
                break;
        }
        printf("\n");
    }

    free(books);
    books = NULL;
    return 0;
}

BOOK *AllocateBooks(int count) {
    BOOK *result = NULL;
    result = (BOOK *) malloc(sizeof(BOOK) * count);
    if (result == NULL) printf("���� �޸� �Ҵ� ����\n");
    else memset(result, 0, sizeof(BOOK) * count);
    return result;
}

void InputBooks(BOOK *books, int count) {
    for (int i = 0; i < count; i++) {
        printf("->���� ���� :");
        gets_s(books[i].name, MAX);

        printf("->�� �� �� :");
        gets_s(books[i].writer, MAX);

        printf("->��    �� :");
        scanf("%d", &books[i].price);
        while (getchar() != '\n');
    }
}

void PrintBookInfos(const BOOK *books, int count) {
    printf("\n--- ��ü ���� ��� ---\n");
    for (int i = 0; i < count; i++) {
        printf("%-16s %-16s %4d\n", books[i].name, books[i].writer, books[i].price);
    }
}

// �� �Լ�
int CompareByPrice(const void *e1, const void *e2) {
    const BOOK *p1 = (const BOOK *) e1;
    const BOOK *p2 = (const BOOK *) e2;
    return p2->price - p1->price;
}
