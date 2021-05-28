#ifndef SWSEMINAR_MENU_H
#define SWSEMINAR_MENU_H
#include "Book.h"

// Menu List 출력 & 옵션 선택
int PrintMenusAndSelectOpt();

// Menu 1 : 도서 입력
int InputBook(BOOK *books, int idx);

// Menu 2 & 3 : 도서 검색(저자별, 도서명)
int FindBook(BOOK *books, int cnt, int opt);
int SearchByWriter(char writerToSearch[],BOOK *books, int cnt, int found);
int SearchByName(char nameToSearch[], BOOK *books, int cnt, int found);

// AdditionalMenu(2 & 3) : 검색 도서 수정 및 삭제
int AdditionalMenu(BOOK *books,int idx,int lastIdx);
int PrintAdditionalOpt();
int deleteBook(BOOK *books, int idx, int lastIdx);

// Menu 4 & 5: 도서 정보 출력(가격순, Default::제목정렬)
void PrintBookInfos(BOOK *books, int count, int opt);
int CompareByPrice(const void *e1, const void *e2);
int CompareByName(const void *e1, const void *e2);

#endif;
