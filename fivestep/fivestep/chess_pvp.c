#include<stdio.h>
#include<string.h>
#include<ctype.h>

void chess_play(char **board, int step_count)//���ݵĵڶ������������˼����˵Ĵ���
{
	char column_c;//��ĸ��ʽ��������
	int raw, column;
	char black[2] = "��";
	char white[2] = "��";
	//�������û���������꣬���账��
	printf("��ѡ����һ����������һ�����������磺2\n");
	while (scanf("%d", &raw)!=1 && (1<= raw && raw<=15))
	{
		printf("��Ч���룬������");
		while (getchar() != '\n')
			continue;
	}

	while (getchar() != '\n')
		continue;

	printf("������һ�����������磺B\n");
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
	
	//�����ǽ��û����������ת��Ϊ������ʶ�������
	column_c = toupper(column_c);
	column = column_c - 64;
	raw = 15 - raw;


	if (step_count % 2 == 0)
	{
		strncpy(board[raw][column], black, 2);
	}
	else
	{
		strncpy(board[raw][column], white, 2);
	}
}