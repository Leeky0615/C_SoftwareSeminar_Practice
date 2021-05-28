#include "Book.h"
// 초기 배열 사이즈 입력
int setListSize() {
    int size = 0;
    printf("저장할 도서의 개수 : ");
    scanf("%d", &size);
    while (getchar() != '\n');
    return size;
}
// 메모리 할당
BOOK *AllocateBooks(int count) {
    BOOK *result = NULL;
    result = (BOOK *) malloc(sizeof(BOOK) * count);
    if (result == NULL) {
        printf("동적 메모리 할당 실패\n");
        return NULL;
    } else memset(result, 0, sizeof(BOOK) * count);
    return result;
}

// 저장 정보 수 초과 시 확장 사이즈 입력
int ExtendListSize() {
    int size = 0;
    printf("저장가능한 개수를 초과했습니다.\n");
    printf("확장할 도서의 개수 : ");
    scanf("%d", &size);
    while (getchar() != '\n');
    printf("\n");
    return size;
}
// 메모리 확장
BOOK *ExtendBooks(BOOK *result, int count, int totalSize) {
    BOOK *temp = result;
    result = (BOOK *) realloc(result,sizeof(BOOK) * totalSize);
    if (result == NULL) {
        printf("동적 메모리 할당 실패\n");
        return NULL;
    }else {
        memset(result, 0, sizeof(BOOK) * totalSize);
        // memset을 했기 때문에 기존 배열을 복사해줘야함.
        for (int i = 0; i < count; ++i) {
            strcpy(result[i].name, temp[i].name);
            strcpy(result[i].writer, temp[i].writer);
            result[i].price = temp[i].price;
        }
    }
    return result;
}