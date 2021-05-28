#include <stdio.h>
#include <stdlib.h>
#include <vcruntime_string.h>

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

    // ����� �� �Է�
    printf("��ü ����� �� : ");
    scanf("%d", &cnt);
    while (getchar() != '\n');

    // ���� �޸� �Ҵ�
    loginInfo = AllocateBooks(cnt);
    if (loginInfo == NULL) return -1;

    // ����� ���� �Է·�
   for (int i = 0; i < cnt; ++i) {
        printf("���̵� : ");
        gets_s(loginInfo[i].id,MAX);

        printf("��й�ȣ : ");
        gets_s(loginInfo[i].passwd,MAX);
    }

    // �ؽ�Ʈ ���� ����
    fp = fopen("exercise2.txt", "wb");
    if (fp == NULL) {
        printf("���� ���� ����\n");
        return -1;
    }

    // �ؽ�Ʈ ���Ͽ� ���� (���̳ʸ�)
    fwrite(&cnt, sizeof(int), 1, fp);
    fwrite(loginInfo, sizeof(LOGIN_INFO), cnt, fp);
    fclose(fp);


    // ���̳ʸ� ���� Ȯ��
    fp = fopen("exercise2.txt","rb");
    fread(&cnt, sizeof(int), 1, fp);
    fread(loginInfo, sizeof(LOGIN_INFO), cnt, fp);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("%s %s\n", loginInfo[i].id, loginInfo[i].passwd);
    }
    fclose(fp);

    return 0;
}

LOGIN_INFO *AllocateBooks(int count) {
    LOGIN_INFO *result = NULL;
    result = (LOGIN_INFO *) malloc(sizeof(LOGIN_INFO) * count);
    if (result == NULL) printf("���� �޸� �Ҵ� ����\n");
    else memset(result, 0, sizeof(LOGIN_INFO) * count);
    return result;
}