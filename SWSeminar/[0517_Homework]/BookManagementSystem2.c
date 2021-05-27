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

BOOK *AllocateBooks(int count);
void PrintBookInfos(const BOOK *book, int count);
void InputBooks(BOOK *books, int count);
int CompareByPrice(const void *e1, const void *e2);

int main() {
    BOOK *books = NULL;
    int cnt = 0;
    int saveCnt = 0;
    char bookToSearch[MAX];
    bool bOnLoop = true;
    int found;
    int opt;

    printf("저장할 도서의 개수 : ");
    scanf("%d", &cnt);
    while (getchar() != '\n');

    books = AllocateBooks(cnt);
    if (books == NULL) return -1;

    printf("----도서 관리 프로그램----\n");
    while (bOnLoop) {
        printf("1. 도서 입력\n");
        printf("2. 저자별 검색\n");
        printf("3. 제목 검색\n");
        printf("4. 가격 순으로 정렬\n");
        printf("5. 끝\n");

        printf("메뉴를 선택하세요: ");
        scanf("%d", &opt);
        while (getchar() != '\n');
        printf("\n");
        switch (opt) {
            case 1:
                if(saveCnt == 0){
                    InputBooks(books, cnt);
                    saveCnt++;
                }else printf("이미 도서를 저장했습니다.");
                break;
            case 2:
                printf("-> 저자명 : ");
                gets_s(bookToSearch,MAX); // 검색 파라미터
                if (strcmp(bookToSearch, ".") == 0) break;
                found = -1;
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookToSearch, books[i].writer) == 0) {
                        found = i;
                        break;
                    }
                }
                if(found == -1) printf("목록에 없는 저자명입니다.");
                else{
                    printf("도서 제목: %s\n", books[found].name);
                    printf("저 자 명: %s\n", books[found].writer);
                    printf("가    격 : %d\n", books[found].price);
                }
                break;
            case 3:
                printf("-> 도서제목 : ");
                gets_s(bookToSearch,MAX); // 검색 파라미터
                if (strcmp(bookToSearch, ".") == 0) break;
                found = -1;
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookToSearch, books[i].name) == 0) {
                        found = i;
                        break;
                    }
                }
                if(found == -1) printf("목록에 없는 도서제목입니다.");
                else{
                    printf("도서 제목: %s\n", books[found].name);
                    printf("저 자 명: %s\n", books[found].writer);
                    printf("가    격 : %d\n", books[found].price);
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
                printf("옵션에 맞는 번호를 입력하세요\n");
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
    if (result == NULL) printf("동적 메모리 할당 실패\n");
    else memset(result, 0, sizeof(BOOK) * count);
    return result;
}

void InputBooks(BOOK *books, int count) {
    for (int i = 0; i < count; i++) {
        printf("->도서 제목 :");
        gets_s(books[i].name, MAX);

        printf("->저 자 명 :");
        gets_s(books[i].writer, MAX);

        printf("->가    격 :");
        scanf("%d", &books[i].price);
        while (getchar() != '\n');
    }
}

void PrintBookInfos(const BOOK *books, int count) {
    printf("\n--- 전체 도서 목록 ---\n");
    for (int i = 0; i < count; i++) {
        printf("%-16s %-16s %4d원\n", books[i].name, books[i].writer, books[i].price);
    }
}

int CompareByPrice(const void *e1, const void *e2) {
    const BOOK *p1 = (const BOOK *) e1;
    const BOOK *p2 = (const BOOK *) e2;
    return p2->price - p1->price;
}
