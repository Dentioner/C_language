#include<stdio.h>
int main()
{
	int x = 100;

	printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n",x ,x ,x);

	system("pause");
	return 0;
}