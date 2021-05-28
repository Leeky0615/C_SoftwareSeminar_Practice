#include <stdio.h>
#include <stdlib.h>
#include <vcruntime_string.h>
#include <string.h>

#define MAX 20
#define MAX_BUF 100

typedef struct login_info {
    char id[MAX];
    char passwd[MAX];
} LOGIN_INFO;

FILE *openLoginInfos();
LOGIN_INFO *AllocateBooks(int count);
int CompareById(const void *e1, const void *e2);
void CheckInfo(LOGIN_INFO *loginInfos, int cnt);

int main(){
    FILE *fp;
    LOGIN_INFO *loginInfos = NULL;
    char buffer[MAX_BUF];
    int cnt = 0; // 구조체 배열 크기 (txt의 1번째 줄의 값)
    int line = 0; // txt 의 줄 개수
    int param = 0; // id인지 password인지 구분하기 위함.
    char *temp; // txt의 ID, Password 정보를 나누기 위해 사용

    // 텍스트 파일 열기
    fp = openLoginInfos();
    if (fp == NULL) return -1;

    // 텍스트 파일 읽어 구조체 배열에 저장. & 구조체 크기 리턴
    while(fgets(buffer, MAX_BUF,fp) != NULL){
        if(line == 0){ // 첫번째 줄인 경우 -> 구조체 배열 크기 정보
            cnt = atoi(buffer); // int값만 가져옴
            loginInfos = AllocateBooks(cnt); // 메모리 할당
            if (loginInfos == NULL) return -1; // 할당 실패시 종료
        }else{ // 첫번째 줄이 아닌 경우 -> 구조체 배열 값 정보
            temp = strtok(buffer, " "); // 띄어쓰기로 구분
            while (temp != NULL){ // NULL 이 나오기 전까지
                if(param == 0) { // 첫번째 temp인 경우 -> ID
                    strcpy(loginInfos[line - 1].id, temp); // temp의 값 id에 저장
                } else if(param == 1) { // 2번째 temp인 경우 -> Password
                    temp[strlen(temp) -1] = '\0'; // 마지막 개행 문자 제거
                    strcpy(loginInfos[line - 1].passwd, temp); // temp의 값 password에 저장
                }
                param++;
                temp = strtok(NULL, " ");
            }
        }
        line++; // 다음줄
        param = 0; // id, password 구분하는 param 초기화
    }

    // 로그인
    CheckInfo(loginInfos, cnt);

    free(loginInfos);
    loginInfos = NULL;
    fclose(fp);
    return 0;
}
FILE *openLoginInfos() {
    FILE *file =  fopen("exercise2.txt", "r");
    if (file == NULL) {
        printf("파일 열기 실패\n");
        return NULL;
    }
    return file;
}
LOGIN_INFO *AllocateBooks(int count) {
    LOGIN_INFO *result = NULL;
    result = (LOGIN_INFO *) malloc(sizeof(LOGIN_INFO) * count);
    if (result == NULL) printf("동적 메모리 할당 실패\n");
    else memset(result, 0, sizeof(LOGIN_INFO) * count);
    return result;
}
void CheckInfo(LOGIN_INFO *loginInfos, int cnt) {
    char loginID[MAX];
    char loginPW[MAX];
    qsort(loginInfos, cnt, sizeof(LOGIN_INFO), CompareById);
    printf("==============로그인==============\n");
    printf("ID : ");
    gets_s(loginID, MAX);

    LOGIN_INFO *foundLoginInfo = (LOGIN_INFO*)bsearch(loginID,loginInfos,cnt,sizeof(LOGIN_INFO), CompareById);
    if(foundLoginInfo == NULL) printf("저장되지 않은 아이디입니다.");
    else{
        printf("PASSWORD : ");
        gets_s(loginPW, MAX);

        if(strcmp(loginPW,foundLoginInfo->passwd) == 0) printf("로그인 성공");
        else printf("로그인 실패");
    }
}

int CompareById(const void *e1, const void *e2){
    const LOGIN_INFO *p1 = (const LOGIN_INFO *) e1;
    const LOGIN_INFO *p2 = (const LOGIN_INFO *) e2;
    return strcmp(p1->id, p2->id);
}