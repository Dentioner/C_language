#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#include<time.h>
#include"head.h"

long int Minimax2(char board[][3][3], int step_count,
	bool my_turn, bool ai_first,
	int floor, int coordinate[])
{
	char black[2] = "○";
	char white[2] = "●";
	char temp_blank[2];//用这个来还原棋盘，相当于悔棋一样的
	char *chess;
	char *opponent_chess;

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
	int best_coordinate[2] = { 0,0 };
	long int temp_score = 0;

	if (floor != 0)
	{
		if (my_turn)
		{
			bool initialized = false;//false表示best_score还没有被赋值过
			//for (int a = 0; a < 26; a++)
			for (int a = 0; a<3; a++)
			{
				for (int b = 0; b < 3; b++)
				{

					int raw = a;
					int column = b;
					
						if ((strncmp(board[raw][column], chess, 2) != 0)
							&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
						{

							strncpy(temp_blank, board[raw][column], 2);
							strncpy(board[raw][column], chess, 2);
							//下面这个是在测试的时候输出的，正式使用的时候可以关掉
							DrawBoard(board, 15, 0, 2, coordinate, step_count);

							temp_score = Minimax2(board, step_count + 1,
								!my_turn, ai_first,
								floor - 1, coordinate);



							//if ((temp_score != 0) && (best_score == 0))
							if (!initialized)
							{
								best_score = temp_score;
								initialized = true;

							}
							else
							{

							
								if ((temp_score >= best_score))//这个地方去掉了(temp_score != 0)这个条件，五子棋也需要去掉，可能需要在后面添加上一个“当(temp_score = 0)”的处理语句
								{
									best_score = temp_score;


									if (floor == FLOOR)

									{
										best_coordinate[0] = raw;
										best_coordinate[1] = column;
									}

								}
							}
							//复原
							strncpy(board[raw][column], temp_blank, 2);



						}
					

				}


			}

			//}
		}
		else
		{
			
			bool initialized = false;//false表示best_score还没有被赋值过

			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{

					int raw = a;
					int column = b;
					
					
						if ((strncmp(board[raw][column], chess, 2) != 0)
							&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
						{

							strncpy(temp_blank, board[raw][column], 2);
							strncpy(board[raw][column], chess, 2);


							//下面这个是在测试的时候输出的，正式使用的时候可以关掉
							DrawBoard(board, 15, 0, 2, coordinate, step_count);

							temp_score = Minimax2(board, step_count + 1,
								!my_turn, ai_first,
								floor - 1, coordinate);

							//if ((temp_score != 0) && (best_score == 0))
	//之所以把这里的temp_score != 0也给去掉，是因为如果最后一个枝是一个大于0的数，那么它会直接赋给bestscore
	//但是这一层是越小越好，如果之前有0的枝，但却被替代了，是不合理的
	//例如先搜索到一个打分为0的点，最后一次搜到了打分为100的点，虽然应该向上一层传递0分的，但是由于这里的逻辑判断，传上去了100分
	//但是什么都不写也不行，因为如果有负分，在“传递最小值”的情况下则会无法成为最优值
								//这里应该采用状态机的方法，在搜索第一个值的时候保证会赋给best
							if (!initialized)//初始化best_score

							{
								best_score = temp_score;
								initialized = true;

							}
							else
							{

							
								if ((temp_score <= best_score))//这个地方去掉了(temp_score != 0)这个条件，五子棋也需要去掉，可能需要在后面添加上一个“当(temp_score = 0)”的处理语句
								{
									best_score = temp_score;
									//这里没有那个最外层判定坐标的东西，因为最外层是不可能会出现传递min的情况的

									if (floor == FLOOR)
										//如果是最外层，记录此时坐标
									{
										best_coordinate[0] = raw;
										best_coordinate[1] = column;
									}

								}
							}
							strncpy(board[raw][column], temp_blank, 2);

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
		int best_raw = 0;
		int best_column = 1;
		//int floor_vcx = FLOOR_VCX;//这个是算杀专用floor
		//int fatal_best_coordinate[2] = { 0,1 };
		//找最佳的点与最值
		if (my_turn)
		{
			temp_score = 0;
		
			



				//这个for循环是一开始就有的，别把这个给删了
				for (int raw = 0; raw < 3; raw++)
				{
					for (int column = 0; column < 3; column++)
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
									best_raw = raw;
									best_column = column;

								}
								if (temp_score > best_score)
								{
									best_score = temp_score;
									best_raw = raw;
									best_column = column;
									
								}
								
							}
						}
					}
				}
				


			



			
				best_score = temp_score1 + temp_score2;
			






		}
		else
		{
			
				for (int raw = 0; raw < 3; raw++)
				{
					for (int column =0; column < 3; column++)
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
									best_raw = raw;
									best_column = column;
								}

								if (temp_score < best_score)
								{
									best_score = temp_score;
									best_raw = raw;
									best_column = column;
									//best_coordinate[0] = raw;
										//best_coordinate[1] = column;
								}
								
							}
						}

					}
				}
				


			
			
				best_score = temp_score1 + temp_score2;
			

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
