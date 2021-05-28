#include "Book.h"
#include "Menu.h"
#include "FileIo.h"

int main() {
    FILE *bookFile = NULL;
    BOOK *books = NULL;
    int savedIdx = 0; // ����� �������� �ε���
    int foundIdx; // 3,4 �޴� -> �˻��� �ε���
    bool bOnLoop = true; // 6�� �޴� -> �ݺ� ����

    // �ؽ�Ʈ ���� ���� & ������ ��� ����
    bookFile = openBookList();
    if (bookFile == NULL) return -1;

    // ����� å�� �� �ʱ�ȭ
    int totalSize = setListSize();

    // �ʱ� ���� �޸� �Ҵ� & �Ҵ翡 ������ ��� ����
    books = AllocateBooks(totalSize);
    if (books == NULL) return -1;

    printf("----���� ���� ���α׷�----\n");
    while (bOnLoop) {
        switch (PrintMenusAndSelectOpt()) { //�޴� ��� & �ɼ� ����
            case 1:
                if (savedIdx >= totalSize) { // ����� ������ ���� ��ü ũ�⺸�� ũ�ų� ���ٸ�
                    totalSize += ExtendListSize(); // Ȯ���� ����� �Է� ����.
                    books = ExtendBooks(books, savedIdx, totalSize); // �޸� Ȯ��.
                    if (books == NULL) return -1; // Ȯ�忡 ������ ��� ����
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
                printf("�ɼǿ� �´� ��ȣ�� �Է��ϼ���\n");
                break;
        }
        printf("\n");
    }

    // �ؽ�Ʈ ���Ͽ� ����
    saveBookList(bookFile, books, savedIdx, totalSize);

    // Finalize
    free(books);
    books = NULL;
    fclose(bookFile);
    return 0;
}
