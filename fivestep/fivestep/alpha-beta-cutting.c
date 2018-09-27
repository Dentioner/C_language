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
第0层找三个坐标→给第1层→第1层找3个坐标→给第2层→第二层找3个坐标→
→第二层给3个坐标打分→给第1层最大值/最小值的坐标→第1层获得最大值/最小值的坐标后打分
→给第0层最大值/最小值的坐标→第0层打分→返回给外面一个最优的坐标

//PVE的chess由my_turn决定（暂定）
*/
void Minimax(char board[][17][2], int step_count, 
	bool my_turn, bool ai_first, int floor, char coordinate[])
{//floor为搜索层数
	long int temp = 0;
	long int max[3] = { 0,0,0 };
	long int min[3] = { 0,0,0 };
	int max_coordinate[3][2] = { {0,0},{0,0},{0,0} };
	int min_coordinate[3][2] = { {0,0},{0,0},{0,0} };
	
	char black[2] = "○";
	char white[2] = "●";
	char temp_blank[2];
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
//至此，获得了三个节点的信息
//下面开始递归
	//递归规则待完善
	//传递的坐标是否是指针？
	/*顺序：
第0层找三个坐标→给第1层→第1层找3个坐标→给第2层→第二层找3个坐标→
→第二层给3个坐标打分→给第1层最大值/最小值的坐标→第1层获得最大值/最小值的坐标后打分
→给第0层最大值/最小值的坐标→第0层打分→返回给外面一个最优的坐标
*/
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
	}*/


}
