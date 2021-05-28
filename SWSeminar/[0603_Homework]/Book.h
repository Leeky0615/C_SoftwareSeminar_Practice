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

// 초기 배열 사이즈 입력
int setListSize();
// 메모리 할당
BOOK *AllocateBooks(int count);
// 저장 정보 수 초과 시 확장 사이즈 입력
int ExtendListSize();
// 메모리 확장
BOOK *ExtendBooks(BOOK *result, int count, int totalSize);

#endif;
