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
    int cnt = 0; // ����ü �迭 ũ�� (txt�� 1��° ���� ��)
    int line = 0; // txt �� �� ����
    int param = 0; // id���� password���� �����ϱ� ����.
    char *temp; // txt�� ID, Password ������ ������ ���� ���

    // �ؽ�Ʈ ���� ����
    fp = openLoginInfos();
    if (fp == NULL) return -1;

    // �ؽ�Ʈ ���� �о� ����ü �迭�� ����. & ����ü ũ�� ����
    while(fgets(buffer, MAX_BUF,fp) != NULL){
        if(line == 0){ // ù��° ���� ��� -> ����ü �迭 ũ�� ����
            cnt = atoi(buffer); // int���� ������
            loginInfos = AllocateBooks(cnt); // �޸� �Ҵ�
            if (loginInfos == NULL) return -1; // �Ҵ� ���н� ����
        }else{ // ù��° ���� �ƴ� ��� -> ����ü �迭 �� ����
            temp = strtok(buffer, " "); // ����� ����
            while (temp != NULL){ // NULL �� ������ ������
                if(param == 0) { // ù��° temp�� ��� -> ID
                    strcpy(loginInfos[line - 1].id, temp); // temp�� �� id�� ����
                } else if(param == 1) { // 2��° temp�� ��� -> Password
                    temp[strlen(temp) -1] = '\0'; // ������ ���� ���� ����
                    strcpy(loginInfos[line - 1].passwd, temp); // temp�� �� password�� ����
                }
                param++;
                temp = strtok(NULL, " ");
            }
        }
        line++; // ������
        param = 0; // id, password �����ϴ� param �ʱ�ȭ
    }

    // �α���
    CheckInfo(loginInfos, cnt);

    free(loginInfos);
    loginInfos = NULL;
    fclose(fp);
    return 0;
}
FILE *openLoginInfos() {
    FILE *file =  fopen("exercise2.txt", "r");
    if (file == NULL) {
        printf("���� ���� ����\n");
        return NULL;
    }
    return file;
}
LOGIN_INFO *AllocateBooks(int count) {
    LOGIN_INFO *result = NULL;
    result = (LOGIN_INFO *) malloc(sizeof(LOGIN_INFO) * count);
    if (result == NULL) printf("���� �޸� �Ҵ� ����\n");
    else memset(result, 0, sizeof(LOGIN_INFO) * count);
    return result;
}
void CheckInfo(LOGIN_INFO *loginInfos, int cnt) {
    char loginID[MAX];
    char loginPW[MAX];
    qsort(loginInfos, cnt, sizeof(LOGIN_INFO), CompareById);
    printf("==============�α���==============\n");
    printf("ID : ");
    gets_s(loginID, MAX);

    LOGIN_INFO *foundLoginInfo = (LOGIN_INFO*)bsearch(loginID,loginInfos,cnt,sizeof(LOGIN_INFO), CompareById);
    if(foundLoginInfo == NULL) printf("������� ���� ���̵��Դϴ�.");
    else{
        printf("PASSWORD : ");
        gets_s(loginPW, MAX);

        if(strcmp(loginPW,foundLoginInfo->passwd) == 0) printf("�α��� ����");
        else printf("�α��� ����");
    }
}

int CompareById(const void *e1, const void *e2){
    const LOGIN_INFO *p1 = (const LOGIN_INFO *) e1;
    const LOGIN_INFO *p2 = (const LOGIN_INFO *) e2;
    return strcmp(p1->id, p2->id);
}