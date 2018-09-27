#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"head.h"

/*
������α����
�ȱ���һ�����̣���ÿ��������
�������Ϊ3��Ҳ����������������ǰ����
	��һ�㣺�Ȱ��Ǹ�������ȥ��������ٽ����ӻ�ԭ���ɣ����ߴ���һ������temp����temp�����޸�
	����ȥ֮�󣬴Ӷ��ֵĽǶȿ���Ҳ��������Сֵ��ͬ����3����
	Ȼ���ٵ������������ֵ
	˳��
��0�����������������1�����1����3�����������2����ڶ�����3�������
���ڶ����3�������֡�����1�����ֵ/��Сֵ���������1�������ֵ/��Сֵ���������
������0�����ֵ/��Сֵ���������0���֡����ظ�����һ�����ŵ�����

//PVE��chess��my_turn�������ݶ���
*/
void Minimax(char board[][17][2], int step_count, 
	bool my_turn, bool ai_first, int floor, char coordinate[])
{//floorΪ��������
	long int temp = 0;
	long int max[3] = { 0,0,0 };
	long int min[3] = { 0,0,0 };
	int max_coordinate[3][2] = { {0,0},{0,0},{0,0} };
	int min_coordinate[3][2] = { {0,0},{0,0},{0,0} };
	
	char black[2] = "��";
	char white[2] = "��";
	char temp_blank[2];
	char *chess;
	char *opponent_chess;
	//�������ڽ���ai���֡��غ����롰�Ƿ����ҷ��غϡ��Ĺ�ϵ
	if (ai_first)
	{
		chess = black;
		opponent_chess = white;
		if ((step_count % 2) == 0)//���step����������2�Ļ������ǰ�����
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


	//���if������ڱ���һ�����̣���ÿ�������֣��������/��С������ǰ����
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
//���ˣ�����������ڵ����Ϣ
//���濪ʼ�ݹ�
	//�ݹ���������
	//���ݵ������Ƿ���ָ�룿
	/*˳��
��0�����������������1�����1����3�����������2����ڶ�����3�������
���ڶ����3�������֡�����1�����ֵ/��Сֵ���������1�������ֵ/��Сֵ���������
������0�����ֵ/��Сֵ���������0���֡����ظ�����һ�����ŵ�����
*/
	//�ݹ麯����д���ο���P257
	/*
	if (floor != 0)//ֻҪ����������һ�� 
	{ 
		Minimax(board, step_count + 1, !my_turn, ai_first, floor - 1, coordinate);
		if (((FLOOR - floor) % 2) == 0)//�������������ż���Ļ�
		{
			*coordinate = **max_coordinate;
		}
		else
		{
			*coordinate = **min_coordinate;
		}
	} 
	else//��ײ�
	{ 
		if (((FLOOR - floor) % 2) == 0)//�������������ż���Ļ�
		{
			*coordinate = **max_coordinate;
		}
		else
		{
			*coordinate = **min_coordinate;
		}
	}*/


}
