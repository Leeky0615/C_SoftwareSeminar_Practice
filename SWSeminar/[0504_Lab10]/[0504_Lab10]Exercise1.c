//
// ������ �迭�� ������ �迭�� ���ڷ� �����Ͽ� ������ �迭�� �κ�����
// ������ �迭�� ���ϴ� �Լ��� �����Ͻÿ�. �׸��� �� �Լ��� �̿��ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ��) a[i][0] ~ a[i][9] ������ �κ����� b[i]�� ���ϱ�
// ������ �迭�� �� 1ũ��� ������ ���� �����Ƿ� �Լ��� ���ڷ� �����ϰ�, �� 2ũ��� 10�̶�� ����.

#include <stdio.h>
#define MAX 3

void getSum(int (*pSA)[10], int *pRA);

int main(void){
    int sumArr[MAX][10] = {
            {0,1,2,3,4,5,6,7,8,9},
            {10,11,12,13,14,15,16,17,18,19},
            {20,21,22,23,24,25,26,27,28,29}
    };
    int resultArr[MAX];

    getSum(sumArr,resultArr);

    return 0;
}

void getSum(int (*pSA)[10], int *pRA){
    for (int i = 0; i < MAX; i++) {
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += pSA[i][j];
        }
        pRA[i] = sum;
        printf("resultArr[%d]: %d\n", i, pRA[i]);
    }
}