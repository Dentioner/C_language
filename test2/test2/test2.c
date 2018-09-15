#include<stdio.h>

int main()
{
	int p[5] = { 1551 };
	if (p == &p[0])
	{
		printf("OK\n");
	}
	printf("%p\n", &p);
	printf("%p\n", p);
	return 0;
}