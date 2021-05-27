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
    BOOK *books[MAX_ARRAY] = {NULL}; // 구조체 배열
    int cnt = 0;
    int opt = 0; // 옵션 번호

    char bookToSearch[MAX];
    int found;

    bool bOnLoop = true; // opt=5 (끝)
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
                if (cnt >= MAX_ARRAY) printf("저장 가능한 책의 수를 초과했습니다.\n");
                else{
                    books[cnt] = (BOOK*)malloc(sizeof(BOOK));
                    memset(books[cnt], 0, sizeof(BOOK));
                    printf("->도서 제목 :");
                    gets_s(books[cnt]->name,MAX);
                    printf("->저 자 명 :");
                    gets_s(books[cnt]->writer, MAX);
                    printf("->가    격 :");
                    scanf("%d", &books[cnt]->price);
                    while (getchar() != '\n');
                    cnt++;
                }
                break;
            case 2:
                printf("-> 저자명 : ");
                gets_s(bookToSearch,MAX); // 검색 파라미터
                if (strcmp(bookToSearch, ".") == 0) break;
                found = -1;
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookToSearch, books[i]->writer) == 0) {
                        found = i;
                        break;
                    }
                }
                if(found == -1) printf("목록에 없는 저자명입니다.");
                else{
                    printf("도서 제목: %s\n", books[found]->name);
                    printf("저 자 명: %s\n", books[found]->writer);
                    printf("가    격 : %d\n", books[found]->price);
                }
                break;
            case 3:
                printf("-> 도서제목 : ");
                gets_s(bookToSearch,MAX); // 검색 파라미터
                if (strcmp(bookToSearch, ".") == 0) break;
                found = -1;
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookToSearch, books[i]->name) == 0) {
                        found = i;
                        break;
                    }
                }
                if(found == -1) printf("목록에 없는 도서제목입니다.");
                else{
                    printf("도서 제목: %s\n", books[found]->name);
                    printf("저 자 명: %s\n", books[found]->writer);
                    printf("가    격 : %d\n", books[found]->price);
                }
                break;
            case 4:
                qsort(books, cnt, sizeof(BOOK*), CompareByPrice);
                printf("\n--- 전체 도서 목록 ---\n");
                for (int i = 0; i < cnt; i++) {
                    printf("%-16s %-16s %4d\n", books[i]->name, books[i]->writer, books[i]->price);
                }
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
