#include <stdio.h>
#include <string.h>

typedef struct product {
	char name[20];
	int price;
	int stock;
}PRODUCT;

int main(void) {
	PRODUCT prd1 = { "A45000, 50 };
	PRODUCT prd2 = { "??????", ????", 10000, 3 };
	PRODUCT prd3 = { "?????", 25000, 10 };
	PRODUCT* prd[] = { &prd1, &prd2, &prd3 };

	int count = sizeof(prd) / sizeof(prd[0]);
	int i;

	for (i = 0; i < count; i++)
	{
		printf("%-20s %8d %10d", prd[i]->name, prd[i]->price, prd[i]->stock);
		if (prd[i]->stock < 10) {
			printf("  ==> ??????!!\n");
		}
		else {
			printf("\n");
		}
	}

	return 0;
}