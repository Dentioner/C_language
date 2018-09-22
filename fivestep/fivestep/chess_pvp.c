#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

void chess_play(char board[][17][2], int step_count)//传递的第二个参数是下了几局了的次数
{
	char column_c;//字母形式的纵坐标
	int raw, column;
	char black[2] = "○";
	char white[2] = "●";
	bool invaluable_coordinate = true;//判断选择的那个坐标上面是不是已经覆盖了棋子了
	

	while (invaluable_coordinate)
	{
		//下面是用户输入的坐标，还需处理
		printf("请选择下一步，先输入一个行数，例如：2\n");
		//下面这个while要优化一下，先写一个while循环，用两个if语句
		//分别判断scanf("%d", &raw) != 1与 (1 >= raw || 15 <= raw)
		//有一个错误就continue
		//待完成
		while ((scanf("%d", &raw) != 1) && (1 >= raw || 15 <= raw))
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
		//判断是否该坐标已经有棋子了
		if (strncmp(board[raw][column], black, 2) == 0 
			|| strncmp(board[raw][column], white, 2) == 0)
		{
			printf("该位置已经有棋子了，请重新选择一个坐标\n");
			continue;
		}
		else
		{
			invaluable_coordinate = false;
		}
	
	}

	if (step_count % 2 == 0)
	{
		strncpy(board[raw][column], black, 2);
	}
	else
	{
		strncpy(board[raw][column], white, 2);
	}
}