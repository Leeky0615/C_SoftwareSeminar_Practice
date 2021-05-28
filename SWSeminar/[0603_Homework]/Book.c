#include "Book.h"
// �ʱ� �迭 ������ �Է�
int setListSize() {
    int size = 0;
    printf("������ ������ ���� : ");
    scanf("%d", &size);
    while (getchar() != '\n');
    return size;
}
// �޸� �Ҵ�
BOOK *AllocateBooks(int count) {
    BOOK *result = NULL;
    result = (BOOK *) malloc(sizeof(BOOK) * count);
    if (result == NULL) {
        printf("���� �޸� �Ҵ� ����\n");
        return NULL;
    } else memset(result, 0, sizeof(BOOK) * count);
    return result;
}

// ���� ���� �� �ʰ� �� Ȯ�� ������ �Է�
int ExtendListSize() {
    int size = 0;
    printf("���尡���� ������ �ʰ��߽��ϴ�.\n");
    printf("Ȯ���� ������ ���� : ");
    scanf("%d", &size);
    while (getchar() != '\n');
    printf("\n");
    return size;
}
// �޸� Ȯ��
BOOK *ExtendBooks(BOOK *result, int count, int totalSize) {
    BOOK *temp = result;
    result = (BOOK *) realloc(result,sizeof(BOOK) * totalSize);
    if (result == NULL) {
        printf("���� �޸� �Ҵ� ����\n");
        return NULL;
    }else {
        memset(result, 0, sizeof(BOOK) * totalSize);
        // memset�� �߱� ������ ���� �迭�� �����������.
        for (int i = 0; i < count; ++i) {
            strcpy(result[i].name, temp[i].name);
            strcpy(result[i].writer, temp[i].writer);
            result[i].price = temp[i].price;
        }
    }
    return result;
}