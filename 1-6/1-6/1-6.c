#include<stdio.h>

void main(void)
{
	int c;
	printf("Please enter a char.\n");
	c = (getchar() != EOF);
	printf("(getchar() != EOF) = %d\n", c);
}