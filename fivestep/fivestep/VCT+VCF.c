#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"
#include<time.h>
//算杀函数
//数组的第一维度是搜索深度
int fatal_priority[6][20][2] =
{
	{
		{0,0},{0,0},{0,0},{0,0},{0,0},//自己的活三
		{0,0},{0,0},{0,0},{0,0},{0,0},//对面的活三
		{0,0},{0,0},{0,0},{0,0},{0,0},//自己的冲四
		{0,0},{0,0},{0,0},{0,0},{0,0},//对面的冲四
	},
	//下同
	{
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
	},

	{
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
	},

	{
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
	},
	{
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
	},
	{
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0},{0,0},
	}
};
long int fatal_best_score_of_upper[6] = { -89999900 , 89999900 , -89999900, 89999900 , -89999900, 89999900 };//给minimax里面的剪枝用的
bool fatal_not_in_the_same_branch[6] = { true, true, true, true, true, true };
long int fatal_step(char board[][17][2], int step_count,
	bool my_turn, bool ai_first,
	int floor, int coordinate[], long int fatal_best_score_of_upper[], int fatal_priority[][20][2], bool fatal_not_in_the_same_branch[])
{
	char black[2] = "○";
	char white[2] = "●";
	char temp_blank[2];//用这个来还原棋盘，相当于悔棋一样的
	char *chess;
	char *opponent_chess;
	bool final_hit = false;
	//bool valid_coordinate = false;
	//下面是在建立ai先手、回合数与“是否是我方回合”的关系

	if ((step_count % 2) == 0)
	{
		chess = black;
		opponent_chess = white;
		if (ai_first)
		{
			my_turn = true;
		}
		else
		{
			my_turn = false;
		}
	}
	else
	{
		chess = white;
		opponent_chess = black;
		if (ai_first)
		{
			my_turn = false;
		}
		else
		{
			my_turn = true;
		}

	}
	long int best_score = 0;
	int best_coordinate[2] = { 0,1 };
	long int temp_score = 0;
	


	if (floor != 0)
	{
		if (my_turn)
		{
			//best_score_of_upper[floor] = 0;
			//先将优先的那些点找到并递归
			final_hit = before_evaluation(board, fatal_priority, floor, step_count, my_turn);
			//下面这个双层的for循环是在测试的时候输出的，正式使用的时候可以关掉
			/*
			for (int test_raw = 0; test_raw < 4; test_raw++)
			{
				for (int test_raw2 = 0; test_raw2 < 26; test_raw2++)
				{

					printf("%d,", priority[test_raw][test_raw2][0]);
					printf("%d", priority[test_raw][test_raw2][1]);
					printf(" ");
				}
				printf("\n");
			}
			*/

			if (final_hit
				&& (FLOOR == floor))
			{//如果发现有连五，直接秒了
				coordinate[0] = fatal_priority[0][0][0];
				coordinate[1] = fatal_priority[0][0][1];
				best_score = evaluation(board, step_count, my_turn, fatal_priority[0][0][0], fatal_priority[0][0][1]);
				return best_score;
			}
			if (!final_hit && (FLOOR == floor))
			{//如果发现对方马上形成连五，但是自己没有连五，赶紧堵上去
				if ((fatal_priority[0][1][0] != 0) || (fatal_priority[0][1][1]) != 0)
				{
					coordinate[0] = fatal_priority[0][1][0];
					coordinate[1] = fatal_priority[0][1][1];
					best_score = evaluation(board, step_count, my_turn, fatal_priority[0][1][0], fatal_priority[0][1][1]);
					return best_score;
				}

			}


			for (int a = 0; a < 26; a++)
			{
				fatal_not_in_the_same_branch[floor - 1] = true;//判断是否在同一分支中，以免误剪枝
				int raw = fatal_priority[FLOOR - floor][a][0];
				int column = fatal_priority[FLOOR - floor][a][1];
				if ((raw != 0) || (column != 0))
				{
					if ((strncmp(board[raw][column], chess, 2) != 0)
						&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
					{
						strncpy(temp_blank, board[raw][column], 2);
						strncpy(board[raw][column], chess, 2);
						//下面这行是在测试的时候使用的，正式使用的时候关掉
						//DrawBoard(board, 15, 0, 2, coordinate, step_count);
						temp_score = Minimax2(board, step_count + 1,
							!my_turn, ai_first,
							floor - 1, coordinate, fatal_best_score_of_upper, fatal_priority, fatal_not_in_the_same_branch);

						//DrawBoard(board, 15, temp_score, 2);
						if ((temp_score != 0) && (best_score == 0))
						{
							best_score = temp_score;

						}
						if ((temp_score != 0) && (temp_score >= best_score))
						{
							best_score = temp_score;

							//valid_coordinate = verify_coordinate(board, raw, column, chess, opponent_chess);
							//if ((floor == FLOOR)&&valid_coordinate)
							if (floor == FLOOR)
								//如果是最外层，记录此时坐标
							{
								best_coordinate[0] = raw;
								best_coordinate[1] = column;
							}
							//这个剪枝待修改
							else
							{
								if ((best_score > fatal_best_score_of_upper[floor]) && (fatal_not_in_the_same_branch[floor]))//剪枝
								{
									strncpy(board[raw][column], temp_blank, 2);
									return 89999900;
								}

							}
						}
						//复原
						strncpy(board[raw][column], temp_blank, 2);
						if (best_score > fatal_best_score_of_upper[floor - 1])
						{
							fatal_best_score_of_upper[floor - 1] = best_score;
							fatal_not_in_the_same_branch[floor - 1] = false;
						}
						if (best_score == 89999900)
						{
							return best_score;
						}

					}
				}




			}
			
		}
		else
		{
			//best_score_of_upper[floor] = 0;
			before_evaluation(board, fatal_priority, floor, step_count, my_turn);
			//下面这个双层的for循环是在测试的时候输出的，正式使用的时候可以关掉
			/*
			for (int test_raw = 0; test_raw < 4; test_raw++)
			{
				for (int test_raw2 = 0; test_raw2 < 26; test_raw2++)
				{

					printf("%d,", priority[test_raw][test_raw2][0]);
					printf("%d", priority[test_raw][test_raw2][1]);
					printf(" ");
				}
				printf("\n");
			}
			*/

			for (int a = 0; a < 26; a++)
			{
				fatal_not_in_the_same_branch[floor - 1] = true;
				int raw = fatal_priority[FLOOR - floor][a][0];
				int column = fatal_priority[FLOOR - floor][a][1];
				if ((raw != 0) || (column != 0))
				{
					if ((strncmp(board[raw][column], chess, 2) != 0)
						&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
					{
						strncpy(temp_blank, board[raw][column], 2);
						strncpy(board[raw][column], chess, 2);
						//下面这个是在测试的时候输出的，正式使用的时候可以关掉
						//DrawBoard(board, 15, 0, 2, coordinate, step_count);
						temp_score = Minimax2(board, step_count + 1,
							!my_turn, ai_first,
							floor - 1, coordinate, fatal_best_score_of_upper, fatal_priority, fatal_not_in_the_same_branch);
						if ((temp_score != 0) && (best_score == 0))
						{
							best_score = temp_score;

						}
						if ((temp_score != 0) && (temp_score <= best_score))
						{
							best_score = temp_score;
							//这里没有那个最外层判定坐标的东西，因为最外层是不可能会出现传递min的情况的

							if (floor == FLOOR)
								//如果是最外层，记录此时坐标
							{
								best_coordinate[0] = raw;
								best_coordinate[1] = column;
							}
							else
							{
								if ((best_score < fatal_best_score_of_upper[floor]) && fatal_not_in_the_same_branch[floor])//剪枝
								{
									strncpy(board[raw][column], temp_blank, 2);
									return -89999900;
								}
							}
						}
						strncpy(board[raw][column], temp_blank, 2);
						if (best_score > fatal_best_score_of_upper[floor - 1])
						{
							fatal_best_score_of_upper[floor - 1] = best_score;
							fatal_not_in_the_same_branch[floor - 1] = false;
						}
						if (best_score == -89999900)
						{
							return best_score;
						}

					}
				}

			}

			
		}

	}
	//最底层↓
	else
	{
		long int temp_score1 = 0;
		long int temp_score2 = 0;
		//找最佳的点与最值
		if (my_turn)
		{
			temp_score = 0;
			//best_score_of_upper[floor] = 0;
			for (int raw = 0; raw < 15; raw++)
			{
				for (int column = 1; column < 16; column++)
				{
					if ((strncmp(board[raw][column], chess, 2) != 0)
						&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
					{
						//temp_score = evaluation(board, step_count, my_turn, raw, column);
						temp_score1 = evaluation(board, step_count, my_turn, raw, column);
						temp_score2 = evaluation(board, step_count + 1, !my_turn, raw, column);
						temp_score = temp_score1 + temp_score2;
						if (temp_score != 0)
						{


							if (best_score == 0)
							{
								best_score = temp_score;

							}
							if (temp_score > best_score)
							{
								best_score = temp_score;
								//best_coordinate[0] = raw;
									//best_coordinate[1] = column;
							}
							/*
							if ((best_score < best_score_of_upper[floor]) && not_in_the_same_branch[floor])//剪枝
							{

								return -89999900;
							}
							*/
						}
					}
				}
			}
		}
		else
		{
			temp_score = 0;
			//best_score_of_upper[floor] = 0;
			for (int raw = 0; raw < 15; raw++)
			{
				for (int column = 1; column < 16; column++)
				{
					if ((strncmp(board[raw][column], chess, 2) != 0)
						&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
					{
						//temp_score = evaluation(board, step_count, my_turn, raw, column);
						temp_score1 = evaluation(board, step_count, my_turn, raw, column);
						temp_score2 = evaluation(board, step_count + 1, !my_turn, raw, column);
						temp_score = temp_score1 + temp_score2;
						if (temp_score != 0)
						{


							if (best_score == 0)
							{
								best_score = temp_score;

							}

							if (temp_score < best_score)
							{
								best_score = temp_score;
								//best_coordinate[0] = raw;
									//best_coordinate[1] = column;
							}
							/*
							if ((best_score > best_score_of_upper[floor]) && not_in_the_same_branch[floor])//剪枝
							{

								return 89999900;
							}
							*/
						}
					}

				}
			}
		}
	}

	//最外层，将要返回一个最终决定的最优坐标
	if ((FLOOR - floor) == 0)
	{
		*coordinate = *best_coordinate;
		*(coordinate + 1) = *(best_coordinate + 1);
		best_score = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
	}



	//strncpy(board[best_coordinate[0]][best_coordinate[1]], temp_blank, 2);


	return best_score;
}

