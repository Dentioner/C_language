#include<stdio.h>
int main()
{
	char ch;
	printf("Please enter a character.\n");
	scanf("%c", &ch);/*&��ʾ���û�������ַ���ֵ��ch*/
	printf("The code for %c is %d.\n", ch, ch);
	
	system("pause");
	return 0;
}