#include<stdio.h>

void main(void)
{
	char ch;//试着用三种方式打印出EOF的值
	printf("Plan1:Please enter the value EOF.\n");
	ch = getchar();
	printf("%d\n", ch);
	printf("Plan2:Here is the value of EOF.\n");
	printf("%d\n", EOF);
	printf("Plan3:Here is the char type of EOF");
	putchar(ch);
	putchar(EOF);

}