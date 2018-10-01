#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"head.h"
//启发式搜索，按照优先级顺序，对分支进行排序，提高剪枝速度
//见https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js
void before_evaluation(char board[][17][2], int priority[][10][2], int floor,
	int step_count, bool my_turn)
//step_count及其后面的几个形参是用来给evaluation的
{
	int my_raw = 0;
	int my_column = 0;
	char black[2] = "○";
	char white[2] = "●";
	long int my_value = 0;
	long int opponent_value = 0;
	bool find_five = false;
	bool find_opponent_five = false;
	bool find_OpenFour = false;
	bool find_opponent_OpenFour = false;
	bool find_DoubleThree = false;
	bool find_opponent_DoubleThree = false;
	bool find_CapFour = false;
	bool find_opponent_CapFour = false;
	bool find_three = false;
	bool find_opponent_three = false;
	for (my_raw = 0; my_raw < 15; my_raw++)
	{
		for (my_column = 1; my_column < 16; my_column++)
		{
			if ((strncmp(board[my_raw][my_column], black, 2) != 0)
				&& (strncmp(board[my_raw][my_column], white, 2) != 0))
			{
				my_value = evaluation(board, step_count, my_turn, my_raw, my_column);
				opponent_value = evaluation(board, step_count + 1, !my_turn, my_raw, my_column);
				if (my_value >= Consecutive_Five)//如果发现了我方连五的地方
				{
					priority[FLOOR - floor][0][0] = my_raw;
					priority[FLOOR - floor][0][1] = my_column;
					find_five = true;
				}
				else if (opponent_value <= -Consecutive_Five)//如果发现了对方连五的地方
				{
					priority[FLOOR - floor][1][0] = my_raw;
					priority[FLOOR - floor][1][1] = my_column;
					find_opponent_five = true;
				}
				else if (my_value >= Open_Four)
				{
					priority[FLOOR - floor][2][0] = my_raw;
					priority[FLOOR - floor][2][1] = my_column;
					find_OpenFour = true;
				}
				else if (opponent_value <= -Open_Four)
				{
					priority[FLOOR - floor][3][0] = my_raw;
					priority[FLOOR - floor][3][1] = my_column;
					find_opponent_OpenFour = true;
				}
				else if (my_value >= 2 * Open_Three)
				{
					priority[FLOOR - floor][4][0] = my_raw;
					priority[FLOOR - floor][4][1] = my_column;
					find_DoubleThree = true;
				}
				else if (opponent_value <= -2 * Open_Three)
				{
					priority[FLOOR - floor][5][0] = my_raw;
					priority[FLOOR - floor][5][1] = my_column;
					find_opponent_DoubleThree = true;
				}
				else if (my_value >= Capped_Four)
				{
					priority[FLOOR - floor][6][0] = my_raw;
					priority[FLOOR - floor][6][1] = my_column;
					find_CapFour = true;
				}
				else if (opponent_value <= -Capped_Four)
				{
					priority[FLOOR - floor][7][0] = my_raw;
					priority[FLOOR - floor][7][1] = my_column;
					find_opponent_CapFour = true;
				}
				else if (my_value >= Open_Three)
				{
					priority[FLOOR - floor][8][0] = my_raw;
					priority[FLOOR - floor][8][1] = my_column;
					find_three = true;
				}
				else if (opponent_value <= -Open_Three)
				{
					priority[FLOOR - floor][9][0] = my_raw;
					priority[FLOOR - floor][9][1] = my_column;
					find_opponent_three = true;
				}

			}
			
			if (find_five
				&& find_opponent_five
				&& find_OpenFour
				&& find_opponent_OpenFour
				&& find_DoubleThree
				&& find_opponent_DoubleThree
				&& find_CapFour
				&& find_opponent_CapFour
				&& find_opponent_three
				&& find_three)
			{
				return;
			}
		
		}
			
			

			
	}
	return;
}