#ifndef SWSEMINAR_BOOK_H
#define SWSEMINAR_BOOK_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 32

typedef struct Book {
    char name[MAX];
    char writer[MAX];
    unsigned int price;
} BOOK;

// �ʱ� �迭 ������ �Է�
int setListSize();
// �޸� �Ҵ�
BOOK *AllocateBooks(int count);
// ���� ���� �� �ʰ� �� Ȯ�� ������ �Է�
int ExtendListSize();
// �޸� Ȯ��
BOOK *ExtendBooks(BOOK *result, int count, int totalSize);

#endif;
