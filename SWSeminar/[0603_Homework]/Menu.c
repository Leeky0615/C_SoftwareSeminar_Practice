#include "Menu.h"

// Menu List ��� & �ɼ� ����
int PrintMenusAndSelectOpt() {
    int opt;

    printf("1. ���� �Է�\n");
    printf("2. ���ں� �˻�\n");
    printf("3. ���� �˻�\n");
    printf("4. ���� ������ ����\n");
    printf("5. ��ü ���� ���� ���\n");
    printf("6. ����\n");

    printf("�޴��� �����ϼ���: ");
    scanf("%d", &opt);
    while (getchar() != '\n');
    printf("\n");

    return opt;
}

// Menu 1 : ���� �Է�
int InputBook(BOOK *books, int idx) {
    printf("->���� ���� :");
    gets_s(books[idx].name, MAX);

    printf("->�� �� �� :");
    gets_s(books[idx].writer, MAX);

    printf("->��    �� :");
    scanf("%d", &books[idx].price);
    while (getchar() != '\n');
    return idx + 1;
}

// Menu 2 & 3 : ���� �˻�(���ں�, ������)
int FindBook(BOOK *books, int cnt, int opt) {
    char searchParam[MAX];
    int found = -1;
    if (opt == 2) {
        printf("=>�� �� �� : ");
        found = SearchByWriter(gets_s(searchParam, MAX), books, cnt, found);
    } else {
        printf("=>���� ���� : ");
        found = SearchByName(gets_s(searchParam, MAX), books, cnt, found);
    }
    if (found == -1) printf("��Ͽ� ���� ���ڸ��Դϴ�.");
    else {
        printf("\n=================�˻� ���=================\n");
        printf("%-16s %-16s %4d��\n", books[found].name, books[found].writer, books[found].price);
    }
    return found;
}

int SearchByWriter(char writerToSearch[], BOOK *books, int cnt, int found) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(writerToSearch, books[i].writer) == 0) {
            found = i;
            break;
        }
    }
    return found;
}

int SearchByName(char nameToSearch[], BOOK *books, int cnt, int found) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(nameToSearch, books[i].name) == 0) {
            found = i;
            break;
        }
    }
    return found;
}

// AdditionalMenu(2 & 3) : �˻� ���� ���� �� ����
int AdditionalMenu(BOOK *books,int idx,int lastIdx){
    int preIdx = lastIdx;
    switch (PrintAdditionalOpt()) {
        case 1:
            printf("������ ���� ���� �Է�\n");
            InputBook(books, idx);
            break;
        case 2:
            printf("�ش� ���� ������ �����Ǿ����ϴ�.\n");
            preIdx = deleteBook(books, idx,lastIdx);
            break;
        case 3:
            printf("���� �޴��� �̵��մϴ�.\n");
            break;
        default:
            printf("�ɼǿ� �´� ��ȣ�� �Է��ϼ���\n");
            break;
    }
    return preIdx;
}

int PrintAdditionalOpt() {
    int opt;
    printf("\n*�߰� �޴� - ���� �� ����\n");
    printf(" 1. ���� ���� ����\n");
    printf(" 2. ���� ���� ����\n");
    printf(" 3. �Ѿ��\n");

    printf("�޴��� �����ϼ���: ");
    scanf("%d", &opt);
    while (getchar() != '\n');
    printf("\n");

    return opt;
}

int deleteBook(BOOK *books, int idx, int lastIdx){
    for (int i = idx; i < lastIdx; i++) {
        memcpy(&books[i], &books[i + 1], sizeof(BOOK));
    }
    return lastIdx-1;
}

// Menu 4 & 5: ���� ���� ���(���ݼ�, Default::��������)
void PrintBookInfos(BOOK *books, int count, int opt) {
    if (opt == 4) qsort(books, count, sizeof(BOOK), CompareByPrice);
    else qsort(books, count, sizeof(BOOK), CompareByName);
    printf("\n================= ��ü ���� ��� =================\n");
    for (int i = 0; i < count; i++) {
        printf("%-16s %-16s %4d��\n", books[i].name, books[i].writer, books[i].price);
    }
}

int CompareByPrice(const void *e1, const void *e2) {
    const BOOK *p1 = (const BOOK *) e1;
    const BOOK *p2 = (const BOOK *) e2;
    return p2->price - p1->price;
}

int CompareByName(const void *e1, const void *e2) {
    const BOOK *p1 = (const BOOK *) e1;
    const BOOK *p2 = (const BOOK *) e2;
    return strcmp(p1->name, p2->name);
}