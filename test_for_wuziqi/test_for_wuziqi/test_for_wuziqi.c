#include<stdio.h>
#include<string.h>

int main()
{
	char column_c;//��ĸ��ʽ��������
	int raw, column;
	//char black[2] = "��";
	//char white[2] = "��";
	//�������û���������꣬���账��
	//printf("��ѡ����һ����������һ�����������磺2\n");
	while (scanf("%d", &raw)!=1 && (1<= raw && raw<=15))
	{
		printf("��Ч���룬������");
		while (getchar() != '\n')
			continue;
	}

	while (getchar() != '\n')
			continue;

	//printf("������һ�����������磺B\n");
	column_c = getchar();
	while (getchar() != '\n')
		continue;
	while (column_c<'A' || (column_c > 'Z'&&column_c < 'a') || column_c>'z')
	{
		printf("��Ч���룬������");
		
		column_c = getchar();
		while (getchar() != '\n')
			continue;

	}

	return 0;

}