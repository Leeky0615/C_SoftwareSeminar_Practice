#include "Book.h"
#include "Menu.h"
#include "FileIo.h"

int main() {
    FILE *bookFile = NULL;
    BOOK *books = NULL;
    int savedIdx = 0; // 저장된 도서정보 인덱스
    int foundIdx; // 3,4 메뉴 -> 검색된 인덱스
    bool bOnLoop = true; // 6번 메뉴 -> 반복 상태

    // 텍스트 파일 열기 & 실패한 경우 종료
    bookFile = openBookList();
    if (bookFile == NULL) return -1;

    // 저장될 책의 수 초기화
    int totalSize = setListSize();

    // 초기 동적 메모리 할당 & 할당에 실패한 경우 종료
    books = AllocateBooks(totalSize);
    if (books == NULL) return -1;

    printf("----도서 관리 프로그램----\n");
    while (bOnLoop) {
        switch (PrintMenusAndSelectOpt()) { //메뉴 출력 & 옵션 선택
            case 1:
                if (savedIdx >= totalSize) { // 저장된 정보의 수가 전체 크기보다 크거나 같다면
                    totalSize += ExtendListSize(); // 확장할 사이즈를 입력 받음.
                    books = ExtendBooks(books, savedIdx, totalSize); // 메모리 확장.
                    if (books == NULL) return -1; // 확장에 실패한 경우 종료
                }
                savedIdx = InputBook(books, savedIdx);
                break;
            case 2:
                foundIdx = FindBook(books, savedIdx, 2);
                if(foundIdx != -1) savedIdx = AdditionalMenu(books, foundIdx, savedIdx);
                break;
            case 3:
                foundIdx = FindBook(books, savedIdx, 3);
                if(foundIdx != -1) savedIdx = AdditionalMenu(books, foundIdx, savedIdx);
                break;
            case 4:
                PrintBookInfos(books, savedIdx, 4);
                break;
            case 5:
                PrintBookInfos(books, savedIdx, 5);
                break;
            case 6:
                bOnLoop = false;
                break;
            default:
                printf("옵션에 맞는 번호를 입력하세요\n");
                break;
        }
        printf("\n");
    }

    // 텍스트 파일에 저장
    saveBookList(bookFile, books, savedIdx, totalSize);

    // Finalize
    free(books);
    books = NULL;
    fclose(bookFile);
    return 0;
}
