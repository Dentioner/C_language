#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//形态的定义见https://www.cnblogs.com/songdechiu/p/5768999.html
//https://baike.1688.com/doc/view-d3091513.html

#define Consecutive_Five 10000000//V连五
#define Open_Four 1000000//V活四
#define Open_Three 100000//V活三
#define Gapped_Two_Two 100050//V下面三种都是冲四，这种是两个2子之间缺了一个子  ●●？●●
#define Capped_Four 100050//V这种冲四是一头被堵住的冲四   ○●●●●和●●●●○
#define Gapped_Four 100050//V这种冲四是一个活三与一个单独的子之间空了一格  ●?●●●
#define Gapped_Three 100000//V这种是跳活三，是即将形成活四的三  ●？●●
#define Capped_Three 10000//眠三, 最多只能形成冲四  ○●●●
/*眠三一共有这几种形态：
1. V○●●●__
2. V○●●_●_
3. ○●_●●_
4. ●●__●
5. ●_●_●
6. ○_●●●_○
*/

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

//活三和冲四中的一种一起判断
//分别是形如_●●●__ 和 _●●●_●的
//各自倒过来又是一种：__●●●_和 ●_●●●_
//先来上面那两种
	//水平方向
		//_?●●__或_?●●_●
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw][column + 4], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw][column + 4], chess, 2) != 0)
			&& (strncmp(board[raw][column + 4], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}
	
		//_●?●__或_●?●_●
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw][column + 3], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw][column + 3], chess, 2) != 0)
			&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//_●●?__或_●●?_●
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw][column + 2], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw][column + 2], chess, 2) != 0)
			&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//_●●●_?,这种情况只有冲四有
	if ((strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 4], chess, 2) == 0)
		&& (strncmp(board[raw][column - 5], chess, 2) != 0)
		&& (strncmp(board[raw][column - 5], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0))
	{
		value += Gapped_Four;
	}

	//竖直方向
		//_?●●__或_?●●_●
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw + 4][column], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw + 4][column], chess, 2) != 0)
			&& (strncmp(board[raw + 4][column], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//_●?●__或_●?●_●
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw + 3][column], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw + 3][column], chess, 2) != 0)
			&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}


		//_●●?__或_●●?_●
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw + 2][column], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw + 2][column], chess, 2) != 0)
			&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//_●●●_?,这种情况只有冲四有
	if ((strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 5][column], chess, 2) != 0)
		&& (strncmp(board[raw - 5][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Four;
	}

	//右上左下的情况
		//_?●●__或_?●●_●
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw - 4][column + 4], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw - 4][column + 4], chess, 2) != 0)
			&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

	//_●?●__或_●?●_●
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw - 3][column + 3], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw - 3][column + 3], chess, 2) != 0)
			&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}


	//_●●?__或_●●?_●
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw - 2][column + 2], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw - 2][column + 2], chess, 2) != 0)
			&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

	//_●●●_?,这种情况只有冲四有
	if ((strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 5][column - 5], chess, 2) != 0)
		&& (strncmp(board[raw + 5][column - 5], opponent_chess, 2) != 0))
	{
		value += Gapped_Four;
	}

	//左上右下方向
		//_?●●__或_?●●_●
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw + 4][column + 4], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw + 4][column + 4], chess, 2) != 0)
			&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

	//_●?●__或_●?●_●
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw + 3][column + 3], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw + 3][column + 3], chess, 2) != 0)
			&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}


	//_●●?__或_●●?_●
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw + 2][column + 2], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw + 2][column + 2], chess, 2) != 0)
			&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

	//_●●●_?,这种情况只有冲四有
	if ((strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 5][column - 5], chess, 2) != 0)
		&& (strncmp(board[raw - 5][column - 5], opponent_chess, 2) != 0))
	{
		value += Gapped_Four;
	}

//活三和冲四中的一种一起判断
//分别是形如_●●●__ 和 _●●●_●的
//各自倒过来又是一种：__●●●_和 ●_●●●_
//现在是下面那两种
	//水平方向
		//__●●?_和 ●_●●?_
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw][column - 4], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw][column - 4], chess, 2) != 0)
			&& (strncmp(board[raw][column - 4], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//__●?●_和 ●_●?●_
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw][column - 3], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw][column - 3], chess, 2) != 0)
			&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//__?●●_和 ●_?●●_
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw][column - 2], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw][column - 2], chess, 2) != 0)
			&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//?_●●●_这种情况只有冲四有
	if ((strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 4], chess, 2) == 0)
		&& (strncmp(board[raw][column + 5], chess, 2) != 0)
		&& (strncmp(board[raw][column + 5], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0))
	{
		value += Gapped_Four;
	}

	//竖直方向
		//__●●?_和 ●_●●?_
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw - 4][column], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw - 4][column], chess, 2) != 0)
			&& (strncmp(board[raw - 4][column], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//__●?●_和 ●_●?●_
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw - 3][column], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw - 3][column], chess, 2) != 0)
			&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//__?●●_和 ●_?●●_
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw - 2][column], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw - 2][column], chess, 2) != 0)
			&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//?_●●●_这种情况只有冲四有
	if ((strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 5][column], chess, 2) != 0)
		&& (strncmp(board[raw + 5][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Four;
	}



	//右上左下方向
		//__●●?_和 ●_●●?_
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw + 4][column - 4], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw + 4][column - 4], chess, 2) != 0)
			&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}


		//__●?●_和 ●_●?●_
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw + 3][column - 3], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw + 3][column - 3], chess, 2) != 0)
			&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//__?●●_和 ●_?●●_
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw + 2][column - 2], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw + 2][column - 2], chess, 2) != 0)
			&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//?_●●●_这种情况只有冲四有
	if ((strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 5][column + 5], chess, 2) != 0)
		&& (strncmp(board[raw - 5][column + 5], opponent_chess, 2) != 0))
	{
		value += Gapped_Four;
	}

	//左上右下方向
		//__●●?_和 ●_●●?_
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw - 4][column - 4], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw - 4][column - 4], chess, 2) != 0)
			&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//__●?●_和 ●_●?●_
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw - 3][column - 3], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw - 3][column - 3], chess, 2) != 0)
			&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}


		//__?●●_和 ●_?●●_
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0))
	{
		if ((strncmp(board[raw - 2][column - 2], chess, 2) == 0))
		{
			value += Gapped_Four;
		}
		else if ((strncmp(board[raw - 2][column - 2], chess, 2) != 0)
			&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0))
		{
			value += Open_Three;
		}
	}

		//?_●●●_这种情况只有冲四有
	if ((strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 5][column + 5], chess, 2) != 0)
		&& (strncmp(board[raw + 5][column + 5], opponent_chess, 2) != 0))
	{
		value += Gapped_Four;
	}



//检查冲四●●_●●Gapped22
	//水平方向
		//?●_●●
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 4], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●?_●●
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●●_?●
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●●_●?
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 4], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

	//竖直方向
		//?●_●●
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●?_●●
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●●_?●
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●●_●?
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

	//右上左下方向
		//?●_●●
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●?_●●
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●●_?●
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●●_●?
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

	//左上右下方向
		//?●_●●
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●?_●●
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●●_?●
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}

		//●●_●?
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Gapped_Two_Two;
	}


//检查冲四Capped_Four ○●●●●_，还有一种反方向的在下面，这里先写一种方向
	// 水平方向
		// ○?●●●_
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// ○●?●●_
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}
		// ○●●?●_
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}
		// ○●●●?_
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}
	//竖直方向
		// ○?●●●_
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 4][column], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// ○●?●●_

	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}
		// ○●●?●_
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}
		// ○●●●?_
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

	//右上左下方向
		// ○?●●●_
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// ○●?●●_
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// ○●●?●_
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// ○●●●?_
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

	//左上右下方向
		// ○?●●●_
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// ○●?●●_
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// ○●●?●_
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// ○●●●?_
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

//冲四的另外一种方向_●●●●○
	// 水平方向
		// _●●●?○
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}
		// _●●?●○
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// _●?●●○
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// _?●●●○
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

	//竖直方向
		// _●●●?○
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 4][column], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// _●●?●○
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// _●?●●○
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// _?●●●○
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

	//右上左下方向
		// _●●●?○
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}
	
		// _●●?●○
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// _●?●●○
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// _?●●●○
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

	//左上右下方向
		// _●●●?○
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// _●●?●○
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}
		
		
		// _●?●●○
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}

		// _?●●●○
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0))
	{
		value += Capped_Four;
	}


//检查跳活三Gapped_Three  _●_●●_与_●●_●_
	
	//水平方向
	//先检查_●_●●_
		//_?_●●_
	if ((strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●_?●_
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●_●?_
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

	//再检查_●●_●_
		//_●●_?_
	if ((strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●?_●_
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_?●_●_
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}


	//竖直方向
	//先检查_●_●●_
		//_?_●●_
	if ((strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●_?●_
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●_●?_
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

	//再检查_●●_●_
		//_●●_?_
	if ((strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●?_●_
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_?●_●_
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

	//右上左下方向
	//先检查_●_●●_
		//_?_●●_
	if ((strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●_?●_
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●_●?_
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

	//再检查_●●_●_
		//_●●_?_
	if ((strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●?_●_
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_?●_●_
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

	//左上右下方向
	//先检查_●_●●_
		//_?_●●_
	if ((strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●_?●_
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●_●?_
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

	//再检查_●●_●_
		//_●●_?_
	if ((strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_●?_●_
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

		//_?●_●_
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Gapped_Three;
	}

//检查眠三：Capped_Three
//1. ○●●●__与__●●●○型
	//水平方向
	//先是○●●●__
		//○?●●__

	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●?●__

	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●●?__

	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//再是__●●●○
		//__●●?○

	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//__●?●○

	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//__?●●○

	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//竖直方向
	//先是○●●●__
		//○?●●__

	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●?●__

	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●●?__

	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//再是__●●●○
		//__●●?○

	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//__●?●○

	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//__?●●○

	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//右上左下方向
	//先是○●●●__
		//○?●●__

	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●?●__

	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●●?__

	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//再是__●●●○
		//__●●?○

	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//__●?●○

	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//__?●●○

	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//左上右下方向
	//先是○●●●__
		//○?●●__

	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●?●__
	
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●●?__

	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//再是__●●●○
		//__●●?○

	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//__●?●○

	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//__?●●○

	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

//2.○●●_●_与_●_●●○
	//水平方向
	//先是○●●_●_
		//○?●_●_
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●?_●_
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●●_?_
	if ((strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//再是_●_●●○
		//_●_●?○
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//_●_?●○
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//_?_●●○
	if ((strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//竖直方向
	//先是○●●_●_
		//○?●_●_
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●?_●_
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●●_?_
	if ((strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//再是_●_●●○
		//_●_●?○
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//_●_?●○
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//_?_●●○
	if ((strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//右上左下方向
	//先是○●●_●_
		//○?●_●_
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●?_●_
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●●_?_
	if ((strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//再是_●_●●○
		//_●_●?○
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//_●_?●○
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//_?_●●○
	if ((strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//左上右下方向
	//先是○●●_●_
		//○?●_●_
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●?_●_
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//○●●_?_
	if ((strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

	//再是_●_●●○
		//_●_●?○
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//_●_?●○
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

		//_?_●●○
	if ((strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) == 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0))
	{
		value += Capped_Three;
	}

//3.○●_●●_与_●●_●○
	//水平方向
	//先是○●_●●_
		//○?_●●_
	if ((strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0))
		//没写完
}





