#include<stdio.h>
int main()
{/*
	int i,j;
	for (i = 1;i < 5; i++)
	{
		for (j = 1; j < 9; j++)
		{
			printf("$");
		}
		printf("\n");
	}
	*/
	char ch;
	
	scanf("%c", &ch);
	while (ch != 'g')
	{
		printf("%c", ++ch);
		scanf("%c", &ch);//如果不要这行，系统只会检测最开始输入的第一个字母，即使输入的是一大句话。这样就会陷入无限死循环了。
	}
	system("pause");
	return 0;
}