#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 40
#define CNT 5
typedef struct font {
    char faceName[MAX];
    unsigned int size;
    int weight;
} FONT;

int compareByName(const void *e1, const void *e2);
int main(void) {
    FONT *foundFont = NULL;
    char fontToSearch[MAX];
    FONT fontList[CNT]={
            {"궁서",10,2},
            {"돋움",14,3},
            {"고딕",16,1},
            {"바탕",20,5},
            {"굴림",11,4},
    };

    qsort(fontList, CNT, sizeof(FONT), compareByName);
    while(1){
        char opt;

        printf("검색할 폰트명:");
        gets_s(fontToSearch,MAX);

        foundFont = bsearch(&fontToSearch,fontList,CNT,sizeof(FONT), (char*)compareByName);
        printf("폰트명: %s\n", foundFont->faceName);
        printf("폰트크기: %d\n", foundFont->size);
        printf("폰트두께: %d\n", foundFont->weight);

        printf("계속 하시겠습니까? (Y/N)");
        scanf("%c", &opt);
        while (getchar() != '\n');

        if(opt=='n' || opt=='N') break;
    }

    return 0;
}
int compareByName(const void *e1, const void *e2){
    const FONT *p1 = (const FONT *) e1;
    const FONT *p2 = (const FONT *) e2;
    return strcmp(p1->faceName, p2->faceName);
}
