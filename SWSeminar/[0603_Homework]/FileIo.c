#include "FileIo.h"

// ���� ����
FILE *openBookList() {
    FILE *file =  fopen("BookList.txt", "w");
    if (file == NULL) {
        printf("���� ���� ����\n");
        return NULL;
    }
    return file;
}

// ���� ����
void saveBookList(FILE *file, BOOK *books, int count, int totalSize){
    fprintf(file, "1. ���� ������ �ִ� ���� ���� ���� : %d��\n", totalSize);
    fprintf(file, "2. ����� ���� ���� ���� : %d��\n", count);
    fprintf(file, "3. ��ü ���� ���\n");
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%-16s %-16s %4d��\n", books[i].name, books[i].writer, books[i].price);
    }
}

