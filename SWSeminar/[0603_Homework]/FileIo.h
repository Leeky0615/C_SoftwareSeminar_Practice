#ifndef SWSEMINAR_FILEIO_H
#define SWSEMINAR_FILEIO_H
#include "Book.h"

// 파일 오픈
FILE *openBookList();

// 파일 저장
void saveBookList(FILE *file, BOOK *books, int count, int totalSize);

#endif;
