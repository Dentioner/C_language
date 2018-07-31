#include<stdio.h>
int main()
{
	printf("type int has a size of %u bytes.\n", sizeof(int));
	printf("type char has a size of %u bytes.\n", sizeof(char));
	printf("type long has a size of %u bytes.\n", sizeof(long));
	printf("type long long has a size of %u bytes.\n", sizeof(long long));
	printf("type double has a size of %u bytes.\n", sizeof(double));
	printf("type long double has a size of %u bytes.\n", sizeof(long double));
	system("pause");
	return 0;
}

