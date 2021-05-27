#include <stdio.h>
#include <stdbool.h>
#include <vcruntime_string.h>
#include <stdlib.h>

#define MAX 20

typedef struct login_info {
    char id[MAX];
    char passwd[MAX];
} LOGIN_INFO;

LOGIN_INFO *AllocateBooks(int count);

int main(){
    FILE *fp;
    LOGIN_INFO *loginInfo = NULL;
    int cnt = 0;

    // 사용자 수 입력
    printf("전체 사용자 수 : ");
    scanf("%d", &cnt);
    while (getchar() != '\n');

    // 동적 메모리 할당
    loginInfo = AllocateBooks(cnt);
    if (loginInfo == NULL) return -1;

    // 사용자 정보 입력력
   for (int i = 0; i < cnt; ++i) {
        printf("아이디 : ");
        gets_s(loginInfo[i].id,MAX);

        printf("비밀번호 : ");
        gets_s(loginInfo[i].passwd,MAX);
    }

    // 텍스트 파일 열기
    fp = fopen("exercise2.txt", "w");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return -1;
    }

    // 텍스트 파일에 저장
    fprintf(fp, "전체 사용자 수 : %d명", cnt);
    for (int i = 0; i < cnt; ++i) {
        fprintf(fp, "%s %s\n", loginInfo[i].id, loginInfo[i].passwd);
    }

    fclose(fp);
    return 0;
}

LOGIN_INFO *AllocateBooks(int count) {
    LOGIN_INFO *result = NULL;
    result = (LOGIN_INFO *) malloc(sizeof(LOGIN_INFO) * count);
    if (result == NULL) printf("동적 메모리 할당 실패\n");
    else memset(result, 0, sizeof(LOGIN_INFO) * count);
    return result;
}