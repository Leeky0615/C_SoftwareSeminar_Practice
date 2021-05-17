#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 32
#define MAX_ARRAY 10
typedef struct book {
    char name[MAX];
    char writer[MAX];
    unsigned int price;
} BOOK;
int CompareByPrice(const void *e1, const void *e2);

int main() {
    BOOK *books[MAX_ARRAY] = {NULL}; // ����ü �迭
    int cnt = 0;
    int opt = 0; // �ɼ� ��ȣ

    char bookToSearch[MAX];
    int found;

    bool bOnLoop = true; // opt=5 (��)
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
                if (cnt >= MAX_ARRAY) printf("���� ������ å�� ���� �ʰ��߽��ϴ�.\n");
                else{
                    books[cnt] = (BOOK*)malloc(sizeof(BOOK));
                    memset(books[cnt], 0, sizeof(BOOK));
                    printf("->���� ���� :");
                    gets_s(books[cnt]->name,MAX);
                    printf("->�� �� �� :");
                    gets_s(books[cnt]->writer, MAX);
                    printf("->��    �� :");
                    scanf("%d", &books[cnt]->price);
                    while (getchar() != '\n');
                    cnt++;
                }
                break;
            case 2:
                printf("-> ���ڸ� : ");
                gets_s(bookToSearch,MAX); // �˻� �Ķ����
                if (strcmp(bookToSearch, ".") == 0) break;
                found = -1;
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookToSearch, books[i]->writer) == 0) {
                        found = i;
                        break;
                    }
                }
                if(found == -1) printf("��Ͽ� ���� ���ڸ��Դϴ�.");
                else{
                    printf("���� ����: %s\n", books[found]->name);
                    printf("�� �� ��: %s\n", books[found]->writer);
                    printf("��    �� : %d\n", books[found]->price);
                }
                break;
            case 3:
                printf("-> �������� : ");
                gets_s(bookToSearch,MAX); // �˻� �Ķ����
                if (strcmp(bookToSearch, ".") == 0) break;
                found = -1;
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookToSearch, books[i]->name) == 0) {
                        found = i;
                        break;
                    }
                }
                if(found == -1) printf("��Ͽ� ���� ���������Դϴ�.");
                else{
                    printf("���� ����: %s\n", books[found]->name);
                    printf("�� �� ��: %s\n", books[found]->writer);
                    printf("��    �� : %d\n", books[found]->price);
                }
                break;
            case 4:
                qsort(books, cnt, sizeof(BOOK*), CompareByPrice);
                printf("\n--- ��ü ���� ��� ---\n");
                for (int i = 0; i < cnt; i++) {
                    printf("%-16s %-16s %4d\n", books[i]->name, books[i]->writer, books[i]->price);
                }
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

    for (int i = 0; i < cnt; i++) {
        free(books[i]);
        books[i] = NULL;
    }
    return 0;
}
int CompareByPrice(const void *e1, const void *e2) {
    const BOOK *p1 = *(const BOOK**) e1;
    const BOOK *p2 = *(const BOOK**) e2;
    return p2->price - p1->price;
}
