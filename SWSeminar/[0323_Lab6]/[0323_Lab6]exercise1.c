#include <stdio.h>

int SumOfArray(int arr[], int size);

int main(void) {
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("1~10까지의 합 : %d\n",SumOfArray(x, 10));
	

	return 0;
}

int SumOfArray(int arr[], int size){
	int result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result += arr[i];
	}
	return result;
}

