#include<stdio.h>
int main()
{
	char ch;
	printf("Please enter a character.\n");
	scanf("%c", &ch);/*&表示把用户输入的字符赋值给ch*/
	printf("The code for %c is %d.\n", ch, ch);
	
	system("pause");
	return 0;
}