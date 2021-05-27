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
            {"�ü�",10,2},
            {"����",14,3},
            {"���",16,1},
            {"����",20,5},
            {"����",11,4},
    };

    qsort(fontList, CNT, sizeof(FONT), compareByName);
    while(1){
        char opt;

        printf("�˻��� ��Ʈ��:");
        gets_s(fontToSearch,MAX);

        foundFont = bsearch(&fontToSearch,fontList,CNT,sizeof(FONT), (char*)compareByName);
        printf("��Ʈ��: %s\n", foundFont->faceName);
        printf("��Ʈũ��: %d\n", foundFont->size);
        printf("��Ʈ�β�: %d\n", foundFont->weight);

        printf("��� �Ͻðڽ��ϱ�? (Y/N)");
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
