#include<stdio.h>

int main()
{
	int count = 0;
	int x = 2;
	int n = 32;
	while (x < n / 2)
	{
		x *= 2;
		count++;
	}

	printf("count = %d\n", count);
	 
	system("pause");
	return 0;
}