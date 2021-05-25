#include <stdio.h>
#include <stdbool.h>

#define MAX_BUF 100

int main(){
    FILE *fp1, *fp2;
    char ch;
    bool status = true;

    fp1 = fopen("a.txt", "r");
    if (fp1 == NULL) {
        printf("���� ���� ����\n");
        return -1;
    }

    fp2 = fopen("b.txt", "r");
    if (fp2 == NULL) {
        printf("���� ���� ����\n");
        return -1;
    }

    while ((ch=fgetc(fp1)) != EOF){
        if(ch != fgetc(fp2)){
            status = false;
            break;
        }
    }
    if(status) printf("�� ������ ������ �����ϴ�.\n");
    else printf("�� ������ ������ �ٸ��ϴ�.\n");


    fclose(fp1);
    fclose(fp2);
    return 0;
}