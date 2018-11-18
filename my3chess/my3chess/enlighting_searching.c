#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include"head.h"


//启发式搜索，按照优先级顺序，对分支进行排序，提高剪枝速度
//见https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js
int before_evaluation(char board[][3][3],  
	int step_count, bool my_turn)
	//step_count及其后面的几个形参是用来给evaluation的
{
	int my_raw = 0;
	int my_column = 0;
	char black[2] = "○";
	char white[2] = "●";
	long int my_value = 0;
	long int opponent_value = 0;
	int status = 0;
	//0表示当前棋局正常
	//1表示当前棋局发现我方杀局
	//2表示当前棋局没有发现我方杀局，但是发现对方杀局
	bool find_five = false;
	bool find_opponent_five = false;
	
	
	bool final_hit = false;//发现我方连五直接返回
	//先初始化，将之前别的分支用过的记录归为0

	
	//下面开始正式记录
	for (my_raw = 0; my_raw < 3; my_raw++)
	{
		for (my_column = 0; my_column < 3; my_column++)
		{
			if ((strncmp(board[my_raw][my_column], black, 2) != 0)
				&& (strncmp(board[my_raw][my_column], white, 2) != 0))
			{
				my_value = evaluation(board, step_count, my_turn, my_raw, my_column);
				my_value = labs(my_value);
				if (my_value >= Consecutive_Five)//如果发现了我方连五的地方
				{
					status = 1;
					return status;
				}
				
				

			}

		} 




	}


	for (my_raw = 0; my_raw < 3; my_raw++)
	{
		for (my_column = 0; my_column < 3; my_column++)
		{
			if ((strncmp(board[my_raw][my_column], black, 2) != 0)
				&& (strncmp(board[my_raw][my_column], white, 2) != 0))
			{
				opponent_value = evaluation(board, step_count + 1, !my_turn, my_raw, my_column);
				opponent_value = labs(opponent_value);
				if (opponent_value >= Consecutive_Five)//如果发现了对方连五的地方
				{
					status = 2;
					return status;
				}


			}

		}




	}


	return status;
}