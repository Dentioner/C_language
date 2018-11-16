#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"head.h"
//形态的定义见https://www.cnblogs.com/songdechiu/p/5768999.html
//https://baike.1688.com/doc/view-d3091513.html



long int evaluation(char board[][3][3], int step_count,
	bool my_turn, int raw, int column)
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
			//●●?型
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&&(column - 2 >= 0 ))//这一行需要修改到五子棋中，新BUG。
	{
		value += Consecutive_Five;
	}
	//●?●型
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (column - 1 >= 0) && (column + 1  <= 2))
	{
		value += Consecutive_Five;
	}

	//?●●型
	if ( (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (column + 2 <= 2))
	{
		value += Consecutive_Five;
	}

	

	//竖直方向
		//●●?型
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (raw - 2 >= 0))
	{
		value += Consecutive_Five;
	}

	//●?●型
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (raw - 1 >= 0) && (raw + 1 <= 2))
	{
		value += Consecutive_Five;
	}

	//?●●型
	if ( (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (raw + 2 <= 2))
	{
		value += Consecutive_Five;
	}

	
	//右上左下方向
		//●●?型

	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (raw + 2 <= 2) && (column - 2 >= 0))
	{
		value += Consecutive_Five;
	}

	//●?●型
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (raw + 1 <= 2) && (column - 1 >= 0)
		&& (raw - 1 >= 0) && (column + 1 <= 2))
	{
		value += Consecutive_Five;
	}

	//?●●型
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (raw - 2 >= 0) && (column + 2 <= 2))
	{
		value += Consecutive_Five;
	}

	

	//左上右下方向
		//●●?型
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
	{
		value += Consecutive_Five;
	}

	//●?●型
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (raw - 1 >= 0) && (column - 1 >= 0)
		&& (raw + 1 <= 2) && (column + 1 <= 2))
	{
		value += Consecutive_Five;
	}

	//?●●型
	if (
		(strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		
		&& (raw + 2 <= 2) && (column + 2 <= 2))
	{
		value += Consecutive_Five;
	}

	
	

	//检查●?_，还有一种反方向的在下面，这里先写一种方向
		// 水平方向
			// ●?_
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (column + 1 <= 2)&&(column  - 1>=0))
		
	{
		value += Capped_Four;
	}

	// ?●_
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column+2], chess, 2) != 0)
		&& (strncmp(board[raw][column+2], opponent_chess, 2) != 0)
		&& (column + 2 <= 2))
		
	{
		value += Capped_Four;
	}
	// ●_?
	if ((strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (column - 2 >= 0))

	{
		value += Capped_Four;
	}
	// ?_●
	if ((strncmp(board[raw][column +2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (column + 2 <= 2) )

	{
		value += Capped_Four;
	}
	// _●?
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column -2], opponent_chess, 2) != 0)
		&& (column - 2 >= 0))
	{
		value += Capped_Four;
	}
	// _?●
	if ((strncmp(board[raw][column +1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))

	{
		value += Capped_Four;
	}
	//竖直方向
			// ●?_
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0))

	{
		value += Capped_Four;
	}

	// ?●_
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0)
		&&(raw + 2 <= 2))

	{
		value += Capped_Four;
	}
	// ●_?
	if ((strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw- 1][column], opponent_chess, 2) != 0)
		&& (raw -2 >= 0))

	{
		value += Capped_Four;
	}
	// ?_●
	if ((strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2))

	{
		value += Capped_Four;
	}
	// _●?
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0))
	{
		value += Capped_Four;
	}
	// _?●
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0))

	{
		value += Capped_Four;
	}

	//右上左下方向
		// ●?_
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 1 ][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))

	{
		value += Capped_Four;
	}

	// ?●_
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw -2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw -2][column + 2], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0)
		&& (column + 2 <= 2))

	{
		value += Capped_Four;
	}
	// ●_?
	if ((strncmp(board[raw+2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw+1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw+1][column - 1], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2) 
		&& (column - 2 >= 0))

	{
		value += Capped_Four;
	}
	// ?_●
	if ((strncmp(board[raw-2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw-1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw-1][column + 1], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0)
		&& (column + 2 <= 2))

	{
		value += Capped_Four;
	}
	// _●?
	if ((strncmp(board[raw+1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw+2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw+2][column - 2], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2)
		&& (column - 2 >= 0))
	{
		value += Capped_Four;
	}
	// _?●
	if ((strncmp(board[raw-1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw+1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw+1][column - 1], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))

	{
		value += Capped_Four;
	}

	//左上右下方向
		
			// ●?_
	if ((strncmp(board[raw - 1][column -1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column+1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column+1], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))

	{
		value += Capped_Four;
	}

	// ?●_
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column+2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column+2], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2)
		&& (column + 2 <= 2))

	{
		value += Capped_Four;
	}
	// ●_?
	if ((strncmp(board[raw - 2][column-2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column-1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column-1], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0)
		&& (column - 2 >= 0))

	{
		value += Capped_Four;
	}
	// ?_●
	if ((strncmp(board[raw + 2][column+2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column+1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column+1], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2)
		&& (column + 2 <= 2))

	{
		value += Capped_Four;
	}
	// _●?
	if ((strncmp(board[raw - 1][column-1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column-2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column-2], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0)
		&& (column - 2 >= 0))
	{
		value += Capped_Four;
	}
	// _?●
	if ((strncmp(board[raw + 1][column+1], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column-1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column-1], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))
		

	{
		value += Capped_Four;
	}

	//如果这个是在评估对方的分数，就输出为负
	//现在的问题是，这个函数是己方对方各用一次，还是一个函数里面将双方都考虑一次？
	//目前的处理是，将这个函数己方对方各用一次，用布尔型my_turn区分

	if (my_turn)
	{
		;
	}
	else
	{
		value *= -1;
	}
	return value;

}





