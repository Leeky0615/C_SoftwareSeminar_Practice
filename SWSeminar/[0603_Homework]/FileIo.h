#ifndef SWSEMINAR_FILEIO_H
#define SWSEMINAR_FILEIO_H
#include "Book.h"

// ���� ����
FILE *openBookList();

// ���� ����
void saveBookList(FILE *file, BOOK *books, int count, int totalSize);

#endif;
