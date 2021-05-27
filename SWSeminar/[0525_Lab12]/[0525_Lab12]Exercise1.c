#include <stdio.h>
#include <stdbool.h>

#define MAX_BUF 100

int main(){
    FILE *fp1, *fp2;
    char ch;
    bool status = true;

    fp1 = fopen("a.txt", "r");
    if (fp1 == NULL) {
        printf("파일 열기 실패\n");
        return -1;
    }

    fp2 = fopen("b.txt", "r");
    if (fp2 == NULL) {
        printf("파일 열기 실패\n");
        return -1;
    }

    while ((ch=fgetc(fp1)) != EOF){
        if(ch != fgetc(fp2)){
            status = false;
            break;
        }
    }
    if(status) printf("두 파일의 내용이 같습니다.\n");
    else printf("두 파일의 내용이 다릅니다.\n");


    fclose(fp1);
    fclose(fp2);
    return 0;
}