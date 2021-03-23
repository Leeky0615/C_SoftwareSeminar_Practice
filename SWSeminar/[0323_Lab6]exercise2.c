#define MAXSIZE 10


#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void RnumberGen(int* A, int size, int range);
void GetMinMax(const int arr[], int size);

int main(void) {
	int x[MAXSIZE];

	RnumberGen(x, MAXSIZE, MAXSIZE);
	
	GetMinMax(x,MAXSIZE);

	return 0;
}


void RnumberGen(int* A, int size, int range)
{
	int i;

	srand(time(NULL));
	for (i = 0; i < size; i++) {
		A[i] = rand() % range + 1;
		printf("%d번 인덱스 : %d\n",i, A[i]);
	}
}

void GetMinMax(int arr[], int size) {
	int max = arr[0];
	int min = arr[0];

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);
}

