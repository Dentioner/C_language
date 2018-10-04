#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"head.h"


/*
下面是伪代码
先遍历一遍棋盘，给每个区域打分
宽度设置为3，也就是搜索最大分数的前三个
	第一层：先把那个棋下下去，在最后再将棋子还原即可，或者创建一个副本temp，在temp里面修改
	下下去之后，从对手的角度看，也就是找最小值，同样找3个点
	然后再迭代，又找最大值
	顺序：


//PVE的chess由my_turn决定（暂定）
*/
/*
int Minimax(char board[][17][2], int step_count, 
	bool my_turn, bool ai_first, int floor, 
	int child_coordinate[], int coordinate[])//coordinate由board.c定义
{//floor为搜索层数,main里面设定为FLOOR的值，目前为3
//递归的最外层需要返回一组坐标coordinate，其余的层数不要返回
	//child_coordinate[]是否还需要？
	long int temp = 0;
	long int max[3] = { 0,0,0 };
	long int min[3] = { 0,0,0 };
	int max_coordinate[3][2] = { {0,0},{0,0},{0,0} };
	int min_coordinate[3][2] = { {0,0},{0,0},{0,0} };
	int child_coordinate1[2] = { 0,0 };
	int child_coordinate2[2] = { 0,0 };
	int child_coordinate3[2] = { 0,0 };//3个子节点的坐标，可能是max，可能是min
	int* best_coordinate;//返回出去的坐标指针
	char black[2] = "○";
	char white[2] = "●";
	char temp_blank[2];//用这个来还原棋盘，相当于悔棋一样的
	char *chess;
	char *opponent_chess;
	//下面是在建立ai先手、回合数与“是否是我方回合”的关系
	if (ai_first)
	{
		chess = black;
		opponent_chess = white;
		if ((step_count % 2) == 0)//如果step数不能整除2的话，就是白子走
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
		if ((step_count % 2) == 0)
		{
			my_turn = false;
		}
		else
		{
			my_turn = true;
		}
	}
	
	strncpy(temp_blank, 
		board[child_coordinate[0]][child_coordinate[1]], 
		2);//将空白处先储存起来，之后再还原

	strncpy(board[child_coordinate[0]][child_coordinate[1]], 
		chess, 2);//假如说上一层觉得这个点最好，在这个点下了棋的基础上研究下面的东西
	//这个if语句是在遍历一遍棋盘，给每个区域打分，搜索最大/最小分数的前三个
	if (my_turn)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				temp = evaluation(board, step_count, my_turn, i, j);
				if ((temp > max[2]) && (temp <= max[1]) && (temp <= max[0]))
				{
					max[2] = temp;
					max_coordinate[2][0] = i;
					max_coordinate[2][1] = j;
				}
				else if ((temp > max[2]) && (temp > max[1]) && (temp <= max[0]))
				{
					max[2] = max[1];
					max_coordinate[2][0] = max_coordinate[1][0];
					max_coordinate[2][1] = max_coordinate[1][0];

					max[1] = temp;
					max_coordinate[1][0] = i;
					max_coordinate[1][1] = j;
				}
				else if((temp > max[2]) && (temp > max[1]) && (temp > max[0]))
				{
					max[2] = max[1];
					max_coordinate[2][0] = max_coordinate[1][0];
					max_coordinate[2][1] = max_coordinate[1][0];
					max[1] = max[0];
					max_coordinate[1][0] = max_coordinate[0][0];
					max_coordinate[1][1] = max_coordinate[0][0];
					max[0] = temp;
					max_coordinate[0][0] = i;
					max_coordinate[0][1] = j;
				}
				else
				{
					;
				}
	
			}
		}

	}

	else 
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 17; j++)
			{
				temp = evaluation(board, step_count, my_turn, i, j);
				if ((temp < min[2]) && (temp >= min[1]) && (temp >= min[0]))
				{
					min[2] = temp;
					min_coordinate[2][0] = i;
					min_coordinate[2][1] = j;
				}
				else if ((temp < min[2]) && (temp < min[1]) && (temp >= min[0]))
				{
					min[2] = min[1];
					min_coordinate[2][0] = min_coordinate[1][0];
					min_coordinate[2][1] = min_coordinate[1][1];
					min[1] = temp;
					min_coordinate[1][0] = i;
					min_coordinate[1][1] = j;
				}
				else if ((temp < min[2]) && (temp < min[1]) && (temp < min[0]))
				{
					min[2] = min[1];
					min_coordinate[2][0] = min_coordinate[1][0];
					min_coordinate[2][1] = min_coordinate[1][1];
					min[1] = min[0];
					min_coordinate[1][0] = min_coordinate[0][0];
					min_coordinate[1][1] = min_coordinate[0][1];
					min[0] = temp;
					min_coordinate[0][0] = i;
					min_coordinate[0][1] = j;
				}
				else
				{
					;
				}

			}
		}
	}

	if (((FLOOR - floor) % 2) == 0)//如果层数为偶数，子节点就是最大的三个坐标点
	{
		child_coordinate1[0] = max_coordinate[0][0];
		child_coordinate1[1] = max_coordinate[0][1];
		child_coordinate2[0] = max_coordinate[1][0];
		child_coordinate2[1] = max_coordinate[1][1];
		child_coordinate3[0] = max_coordinate[2][0];
		child_coordinate3[1] = max_coordinate[2][1];
	}
	else
	{
		child_coordinate1[0] = min_coordinate[0][0];
		child_coordinate1[1] = min_coordinate[0][1];
		child_coordinate2[0] = min_coordinate[1][0];
		child_coordinate2[1] = min_coordinate[1][1];
		child_coordinate3[0] = min_coordinate[2][0];
		child_coordinate3[1] = min_coordinate[2][1];
	}
//至此，获得了三个节点的信息
//下面开始递归
	//递归规则待完善
	//传递的坐标是否是指针？
	/*顺序：
第0层找三个坐标→给第1层→第1层找3个坐标→给第2层→第二层找3个坐标→
→第二层给3个坐标打分→给第1层最大值/最小值的坐标→第1层获得最大值/最小值的坐标后打分
→给第0层最大值/最小值的坐标→第0层打分→返回给外面一个最优的坐标
在这个过程中还要下棋，下完棋之后还得将棋盘变回去

	printf("floor = %d\nFLOOR - floor = %d\n.", floor, FLOOR - floor);
	
	if (floor != 0)//还没到最底层的话就递归
	{
/*
		Minimax(board, step_count + 1, !my_turn,
				ai_first, floor - 1, child_coordinate1);//这3个就是递归表达式
		Minimax(board, step_count + 1, !my_turn,
			ai_first, floor - 1, child_coordinate2);
		Minimax(board, step_count + 1, !my_turn,
			ai_first, floor - 1, child_coordinate3);



	}
	
	
	//到了最底层之后,以及递归回来以后，就要找最值，向上传递指针best_coordinate了
	


	//递归函数重写，参考书P257
	/*
	if (floor != 0)//只要不是最里面一层 
	{ 
		Minimax(board, step_count + 1, !my_turn, ai_first, floor - 1, coordinate);
		if (((FLOOR - floor) % 2) == 0)//如果搜索层数是偶数的话
		{
			*coordinate = **max_coordinate;
		}
		else
		{
			*coordinate = **min_coordinate;
		}
	} 
	else//最底层
	{ 
		if (((FLOOR - floor) % 2) == 0)//如果搜索层数是偶数的话
		{
			*coordinate = **max_coordinate;
		}
		else
		{
			*coordinate = **min_coordinate;
		}
	}


	strncpy(board[child_coordinate[0]][child_coordinate[1]], 
		temp_blank, 2);//将棋盘复原

}*/


long int Minimax2(char board[][17][2], int step_count,
	bool my_turn, bool ai_first,
	int floor, int coordinate[], long int best_score_of_upper[], int priority[][26][2])
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
	/*
	//找最佳的点与最值
	if (my_turn)
	{
		temp_score = 0;
		//在设计优先级函数之前，先如下凑合着用
		//raw和column的搜索范围缩小一点，这样可以减少运算量，棋盘边缘就不搜索了
		for (int raw = 3; raw < 12; raw++)
		{
			for (int column = 3; column < 14; column++)
			{
				temp_score = evaluation(board, step_count, my_turn, raw, column);
				if (temp_score > best_score)
				{
					best_score = temp_score;
					best_coordinate[0] = raw;
					best_coordinate[1] = column;
				}
			}
		}
	}
	else
	{
		temp_score = 0;
		for (int raw = 0; raw < 15; raw++)
		{
			for (int column = 0; column < 17; column++)
			{
				temp_score = evaluation(board, step_count, my_turn, raw, column);
				if (temp_score < best_score)
				{
					best_score = temp_score;
					best_coordinate[0] = raw;
					best_coordinate[1] = column;
				}
			}
		}
	}

	strncpy(temp_blank, board[best_coordinate[0]][best_coordinate[1]], 2);
	strncpy(board[best_coordinate[0]][best_coordinate[1]], chess, 2);
	//下面开始递归
	*/
	//printf("floor = %d\nFLOOR - floor = %d\n.", floor, FLOOR - floor);
	//不是最底层↓

	
	if (floor != 0)
	{
		if (my_turn)
		{
			//先将优先的那些点找到并递归
			final_hit = before_evaluation(board, priority, floor, step_count, my_turn);
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
			
			
			if (final_hit
				&&(FLOOR == floor))
			{//如果发现有连五，直接秒了
				coordinate[0] = priority[0][0][0];
				coordinate[1] = priority[0][0][1];
				best_score = evaluation(board, step_count, my_turn, priority[0][0][0], priority[0][0][1]);
				return best_score;
			}
			if (!final_hit && (FLOOR == floor))
			{//如果发现对方马上形成连五，但是自己没有连五，赶紧堵上去
				if ((priority[0][1][0] != 0) || (priority[0][1][1]) != 0)
				{
					coordinate[0] = priority[0][1][0];
					coordinate[1] = priority[0][1][1];
					best_score = evaluation(board, step_count, my_turn, priority[0][1][0], priority[0][1][1]);
					return best_score;
				}
				
			}
			for (int a = 0; a < 26; a++)
			{
				int raw = priority[FLOOR - floor][a][0];
				int column = priority[FLOOR - floor][a][1];
				if ((raw != 0) || (column != 0))
				{
					if ((strncmp(board[raw][column], chess, 2) != 0)
						&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
					{
						strncpy(temp_blank, board[raw][column], 2);
						strncpy(board[raw][column], chess, 2);
						DrawBoard(board, 15, temp_score, 2);
						temp_score = Minimax2(board, step_count + 1,
							!my_turn, ai_first,
							floor - 1, coordinate, best_score_of_upper, priority);

						//DrawBoard(board, 15, temp_score, 2);
						if ((temp_score != 0) && (best_score == 0))
						{
							best_score = temp_score;

						}
						if (temp_score > best_score)
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
								if (best_score > best_score_of_upper[floor])//剪枝
								{
									strncpy(board[raw][column], temp_blank, 2);
									return 89999900;
								}
							}
						}
						//复原
						strncpy(board[raw][column], temp_blank, 2);
						best_score_of_upper[floor - 1] = best_score;
					}
				}

				


			}
			//这行下面全遍历棋盘的循环先废弃了
			/*
			for (int raw = 0; raw < 15; raw++)
			{
				for (int column = 1; column < 16; column++)
				{//每一个点落子，产生子节点，因此实际上每一个点都会产生255个子节点
					//↓
					if ((strncmp(board[raw][column], chess, 2) != 0)
						&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
					{
						strncpy(temp_blank, board[raw][column], 2);
						strncpy(board[raw][column], chess, 2);
					//	DrawBoard(board, 15, temp_score, 2);
						temp_score = Minimax2(board, step_count + 1,
							!my_turn, ai_first,
							floor - 1, coordinate, best_score_of_upper);
				
							//DrawBoard(board, 15, temp_score, 2);
						if ((temp_score != 0)&&(best_score == 0))
						{
							best_score = temp_score;
							
						}
						if (temp_score > best_score)
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
								if (best_score > best_score_of_upper[floor])//剪枝
								{
									strncpy(board[raw][column], temp_blank, 2);
									return 89999900;
								}
							}
						}
						//复原
						strncpy(board[raw][column], temp_blank, 2);
						best_score_of_upper[floor - 1] = best_score;
					}

					
				}
			}*/
			
		}
		else
		{
			before_evaluation(board, priority, floor, step_count, my_turn);
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

			for (int a = 0; a < 26; a++)
			{
				int raw = priority[FLOOR - floor][a][0];
				int column = priority[FLOOR - floor][a][1];
				if ((raw != 0) || (column != 0))
				{
					if ((strncmp(board[raw][column], chess, 2) != 0)
						&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
					{
						strncpy(temp_blank, board[raw][column], 2);
						strncpy(board[raw][column], chess, 2);
						DrawBoard(board, 15, temp_score, 2);
						temp_score = Minimax2(board, step_count + 1,
							!my_turn, ai_first,
							floor - 1, coordinate, best_score_of_upper, priority);
						if ((temp_score != 0) && (best_score == 0))
						{
							best_score = temp_score;

						}
						if (temp_score < best_score)
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
								if (best_score < best_score_of_upper[floor])//剪枝
								{
									strncpy(board[raw][column], temp_blank, 2);
									return -89999900;
								}
							}
						}
						strncpy(board[raw][column], temp_blank, 2);
						best_score_of_upper[floor - 1] = best_score;
					}
				}
				
			}
			
			//下面是废弃的原来的遍历整个棋盘的循环
			/*
			for (int raw = 0; raw < 15; raw++)
			{
				for (int column = 1; column < 16; column++)
				{
					if ((strncmp(board[raw][column], chess, 2) != 0)
						&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
					{
						strncpy(temp_blank, board[raw][column], 2);
						strncpy(board[raw][column], chess, 2);
						//DrawBoard(board, 15, temp_score, 2);
						temp_score = Minimax2(board, step_count + 1,
							!my_turn, ai_first,
							floor - 1, coordinate, best_score_of_upper);
						if ((temp_score != 0) && (best_score == 0))
						{
							best_score = temp_score;
							
						}
						if (temp_score < best_score)
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
								if (best_score < best_score_of_upper[floor])//剪枝
								{
									strncpy(board[raw][column], temp_blank, 2);
									return -89999900;
								}
							}
						}
						strncpy(board[raw][column], temp_blank, 2);
						best_score_of_upper[floor - 1] = best_score;
					}
				}
			}*/
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
			//在设计优先级函数之前，先如下凑合着用
			//raw和column的搜索范围缩小一点，这样可以减少运算量，棋盘边缘就不搜索了
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
						if (temp_score > best_score_of_upper[floor])//剪枝
						{
							
							return 89999900;
						}
						if (temp_score > best_score)
						{
							best_score = temp_score;
							//best_coordinate[0] = raw;
								//best_coordinate[1] = column;
						}
					}
				}
			}
		}
		else
		{
			temp_score = 0;
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
						if (temp_score < best_score_of_upper[floor])//剪枝
						{

							return -89999900;
						}
						if (temp_score < best_score)
						{
							best_score = temp_score;
							//best_coordinate[0] = raw;
								//best_coordinate[1] = column;
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
