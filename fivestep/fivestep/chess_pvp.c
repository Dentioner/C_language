#include<stdio.h>
#include<string.h>
#include<ctype.h>

void chess_play(char **board, int step_count)//传递的第二个参数是下了几局了的次数
{
	char column_c;//字母形式的纵坐标
	int raw, column;
	char black[2] = "○";
	char white[2] = "●";
	//下面是用户输入的坐标，还需处理
	printf("请选择下一步，先输入一个行数，例如：2\n");
	while (scanf("%d", &raw)!=1 && (1<= raw && raw<=15))
	{
		printf("无效输入，请重试");
		while (getchar() != '\n')
			continue;
	}

	while (getchar() != '\n')
		continue;

	printf("再输入一个列数，例如：B\n");
	column_c = getchar();
	while (getchar() != '\n')
		continue;
	while (column_c<'A' || (column_c > 'Z'&&column_c < 'a') || column_c>'z')
	{
		printf("无效输入，请重试");
		
		column_c = getchar();
		while (getchar() != '\n')
			continue;

	}
	
	//下面是将用户输入的坐标转换为数组能识别的坐标
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