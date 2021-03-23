#include <stdlib.h>
#include <time.h>
#include <stdio.h>



int main(void) {

	return 0;
}


void RnumberGen(int* A, int size, int range)
{
	int i;

	srand(time(NULL));
	for (i = 0; i < size; i++) {
		A[i] = rand() % range + 1;
	}
