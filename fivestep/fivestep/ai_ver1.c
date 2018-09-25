#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define Consecutive_Five 10000000//连五
#define Open_Four 1000000//活四
#define Open_Three 100000//活三
#define Gapped_Two_Two 100050//下面三种都是冲四，这种是两个2子之间缺了一个子  ●●？●●
#define Capped_Four 100050//这种冲四是一头被堵住的冲四   ○●●●●
#define Gapped_Four 100050//这种冲四是一个活三与一个单独的子之间空了一格  ●?●●●
#define Gapped_Three 100000//下面两种是眠三，这种是即将形成活四的眠三  ●？●●
#define Capped_Three 10000//这种眠三最多只能形成冲四  ○●●●

long int evaluation(char board[][17][2], int step_count, bool my_turn,
	int raw, int column)
//step_count的作用是，确认这盘是黑子还是白子
//my_turn 的作用是，确认这盘是我方还是敌方
//raw和column是传递坐标，看看到底是哪个位置需要评估
{
//先确认这把是白子下还是黑子下
	char *chess;
	char *opponent_chess;
	char black[2] = "○";
	char white[2] = "●";
	
	long int value = 0;
	if (step_count % 2)//如果step数不能整除2的话，就是白子
	{
		chess = white;
		opponent_chess = black;
	}
	else
	{
		chess = black;
		opponent_chess = white;
	}

//检查连五
	//水平方向
		//●●●●?型
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}
		//●●●?●型
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●●?●●型
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●?●●●型
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//?●●●●型
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

	//竖直方向
		//●●●●?型
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}
		
		//●●●?●型
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●●?●●型
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●?●●●型

	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//?●●●●型
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

	//右上左下方向
		//●●●●?型

	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●●●?●型
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●●?●●型
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●?●●●型
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//?●●●●型
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

	//左上右下方向
		//●●●●?型
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●●●?●型
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●●?●●型
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//●?●●●型
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}
		
		//?●●●●型
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}


//检查活四
	//水平方向
		//_?●●●_型
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}
		
		//_●?●●_型
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●●?●_型
	if ((strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●●●?_型
	if ((strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

	//竖直方向
		//_?●●●_型
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●?●●_型

	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●●?●_型
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●●●?_型
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

	//右上左下型
		//_?●●●_型
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●?●●_型
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●●?●_型
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●●●?_型
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

	//左上右下型
		//_?●●●_型
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●?●●_型
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●●?●_型
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_●●●?_型
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

//活三
	//水平方向
		//
}





