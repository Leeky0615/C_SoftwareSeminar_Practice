#ifndef SWSEMINAR_MENU_H
#define SWSEMINAR_MENU_H
#include "Book.h"

// Menu List ��� & �ɼ� ����
int PrintMenusAndSelectOpt();

// Menu 1 : ���� �Է�
int InputBook(BOOK *books, int idx);

// Menu 2 & 3 : ���� �˻�(���ں�, ������)
int FindBook(BOOK *books, int cnt, int opt);
int SearchByWriter(char writerToSearch[],BOOK *books, int cnt, int found);
int SearchByName(char nameToSearch[], BOOK *books, int cnt, int found);

// AdditionalMenu(2 & 3) : �˻� ���� ���� �� ����
int AdditionalMenu(BOOK *books,int idx,int lastIdx);
int PrintAdditionalOpt();
int deleteBook(BOOK *books, int idx, int lastIdx);

// Menu 4 & 5: ���� ���� ���(���ݼ�, Default::��������)
void PrintBookInfos(BOOK *books, int count, int opt);
int CompareByPrice(const void *e1, const void *e2);
int CompareByName(const void *e1, const void *e2);

#endif;
