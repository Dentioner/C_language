#include<stdio.h>
int main()
{
	int n = 0;
	size_t intsize;

	intsize = sizeof(int);
	printf("n = %d, n has %lu bytes; all ints have %lu bytes.\n", n, sizeof n, intsize);

	system("pause");
	return 0;
}