#include<stdio.h>
int main()
{
	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d**% d**\n", 42, 42, -42);
	printf("**%5d**%11.9d**%05d**%05.3d**\n", 6, 6, 6, 6);/*为什么整数有小数位数的这种说法啊？%5.3d是什么？*/
	getchar();
	return 0; 
}