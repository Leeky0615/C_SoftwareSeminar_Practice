#include "FileIo.h"

// 파일 오픈
FILE *openBookList() {
    FILE *file =  fopen("BookList.txt", "w");
    if (file == NULL) {
        printf("파일 열기 실패\n");
        return NULL;
    }
    return file;
}

// 파일 저장
void saveBookList(FILE *file, BOOK *books, int count, int totalSize){
    fprintf(file, "1. 저장 가능한 최대 도서 정보 개수 : %d개\n", totalSize);
    fprintf(file, "2. 저장된 도서 정보 개수 : %d개\n", count);
    fprintf(file, "3. 전체 도서 목록\n");
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%-16s %-16s %4d원\n", books[i].name, books[i].writer, books[i].price);
    }
}

