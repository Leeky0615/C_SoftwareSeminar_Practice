#include "Menu.h"

// Menu List 출력 & 옵션 선택
int PrintMenusAndSelectOpt() {
    int opt;

    printf("1. 도서 입력\n");
    printf("2. 저자별 검색\n");
    printf("3. 제목 검색\n");
    printf("4. 가격 순으로 정렬\n");
    printf("5. 전체 도서 정보 출력\n");
    printf("6. 종료\n");

    printf("메뉴를 선택하세요: ");
    scanf("%d", &opt);
    while (getchar() != '\n');
    printf("\n");

    return opt;
}

// Menu 1 : 도서 입력
int InputBook(BOOK *books, int idx) {
    printf("->도서 제목 :");
    gets_s(books[idx].name, MAX);

    printf("->저 자 명 :");
    gets_s(books[idx].writer, MAX);

    printf("->가    격 :");
    scanf("%d", &books[idx].price);
    while (getchar() != '\n');
    return idx + 1;
}

// Menu 2 & 3 : 도서 검색(저자별, 도서명)
int FindBook(BOOK *books, int cnt, int opt) {
    char searchParam[MAX];
    int found = -1;
    if (opt == 2) {
        printf("=>저 자 명 : ");
        found = SearchByWriter(gets_s(searchParam, MAX), books, cnt, found);
    } else {
        printf("=>도서 제목 : ");
        found = SearchByName(gets_s(searchParam, MAX), books, cnt, found);
    }
    if (found == -1) printf("목록에 없는 저자명입니다.");
    else {
        printf("\n=================검색 결과=================\n");
        printf("%-16s %-16s %4d원\n", books[found].name, books[found].writer, books[found].price);
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

// AdditionalMenu(2 & 3) : 검색 도서 수정 및 삭제
int AdditionalMenu(BOOK *books,int idx,int lastIdx){
    int preIdx = lastIdx;
    switch (PrintAdditionalOpt()) {
        case 1:
            printf("수정할 도서 정보 입력\n");
            InputBook(books, idx);
            break;
        case 2:
            printf("해당 도서 정보가 삭제되었습니다.\n");
            preIdx = deleteBook(books, idx,lastIdx);
            break;
        case 3:
            printf("메인 메뉴로 이동합니다.\n");
            break;
        default:
            printf("옵션에 맞는 번호를 입력하세요\n");
            break;
    }
    return preIdx;
}

int PrintAdditionalOpt() {
    int opt;
    printf("\n*추가 메뉴 - 수정 및 삭제\n");
    printf(" 1. 도서 정보 수정\n");
    printf(" 2. 도서 정보 삭제\n");
    printf(" 3. 넘어가기\n");

    printf("메뉴를 선택하세요: ");
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

// Menu 4 & 5: 도서 정보 출력(가격순, Default::제목정렬)
void PrintBookInfos(BOOK *books, int count, int opt) {
    if (opt == 4) qsort(books, count, sizeof(BOOK), CompareByPrice);
    else qsort(books, count, sizeof(BOOK), CompareByName);
    printf("\n================= 전체 도서 목록 =================\n");
    for (int i = 0; i < count; i++) {
        printf("%-16s %-16s %4d원\n", books[i].name, books[i].writer, books[i].price);
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