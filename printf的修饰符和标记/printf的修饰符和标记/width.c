#include<stdio.h>
/*#define PAGES 959*/
int main()
{
	int PAGES;
	printf("Please input a number.\n");
	scanf("%d", &PAGES);
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);

	system("pause");
	return 0;
}
