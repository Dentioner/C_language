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
		scanf("%c", &ch);//�����Ҫ���У�ϵͳֻ�����ʼ����ĵ�һ����ĸ����ʹ�������һ��仰�������ͻ�����������ѭ���ˡ�
	}
	system("pause");
	return 0;
}