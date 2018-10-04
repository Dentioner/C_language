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


//PVE��chess��my_turn�������ݶ���
*/
/*
int Minimax(char board[][17][2], int step_count, 
	bool my_turn, bool ai_first, int floor, 
	int child_coordinate[], int coordinate[])//coordinate��board.c����
{//floorΪ��������,main�����趨ΪFLOOR��ֵ��ĿǰΪ3
//�ݹ���������Ҫ����һ������coordinate������Ĳ�����Ҫ����
	//child_coordinate[]�Ƿ���Ҫ��
	long int temp = 0;
	long int max[3] = { 0,0,0 };
	long int min[3] = { 0,0,0 };
	int max_coordinate[3][2] = { {0,0},{0,0},{0,0} };
	int min_coordinate[3][2] = { {0,0},{0,0},{0,0} };
	int child_coordinate1[2] = { 0,0 };
	int child_coordinate2[2] = { 0,0 };
	int child_coordinate3[2] = { 0,0 };//3���ӽڵ�����꣬������max��������min
	int* best_coordinate;//���س�ȥ������ָ��
	char black[2] = "��";
	char white[2] = "��";
	char temp_blank[2];//���������ԭ���̣��൱�ڻ���һ����
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
	
	strncpy(temp_blank, 
		board[child_coordinate[0]][child_coordinate[1]], 
		2);//���հ״��ȴ���������֮���ٻ�ԭ

	strncpy(board[child_coordinate[0]][child_coordinate[1]], 
		chess, 2);//����˵��һ������������ã��������������Ļ������о�����Ķ���
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

	if (((FLOOR - floor) % 2) == 0)//�������Ϊż�����ӽڵ�����������������
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
//���ˣ�����������ڵ����Ϣ
//���濪ʼ�ݹ�
	//�ݹ���������
	//���ݵ������Ƿ���ָ�룿
	/*˳��
��0�����������������1�����1����3�����������2����ڶ�����3�������
���ڶ����3�������֡�����1�����ֵ/��Сֵ���������1�������ֵ/��Сֵ���������
������0�����ֵ/��Сֵ���������0���֡����ظ�����һ�����ŵ�����
����������л�Ҫ���壬������֮�󻹵ý����̱��ȥ

	printf("floor = %d\nFLOOR - floor = %d\n.", floor, FLOOR - floor);
	
	if (floor != 0)//��û����ײ�Ļ��͵ݹ�
	{
/*
		Minimax(board, step_count + 1, !my_turn,
				ai_first, floor - 1, child_coordinate1);//��3�����ǵݹ���ʽ
		Minimax(board, step_count + 1, !my_turn,
			ai_first, floor - 1, child_coordinate2);
		Minimax(board, step_count + 1, !my_turn,
			ai_first, floor - 1, child_coordinate3);



	}
	
	
	//������ײ�֮��,�Լ��ݹ�����Ժ󣬾�Ҫ����ֵ�����ϴ���ָ��best_coordinate��
	


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
	}


	strncpy(board[child_coordinate[0]][child_coordinate[1]], 
		temp_blank, 2);//�����̸�ԭ

}*/


long int Minimax2(char board[][17][2], int step_count,
	bool my_turn, bool ai_first,
	int floor, int coordinate[], long int best_score_of_upper[], int priority[][26][2])
{
	char black[2] = "��";
	char white[2] = "��";
	char temp_blank[2];//���������ԭ���̣��൱�ڻ���һ����
	char *chess;
	char *opponent_chess;
	bool final_hit = false;
	//bool valid_coordinate = false;
	//�������ڽ���ai���֡��غ����롰�Ƿ����ҷ��غϡ��Ĺ�ϵ

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
	//����ѵĵ�����ֵ
	if (my_turn)
	{
		temp_score = 0;
		//��������ȼ�����֮ǰ�������´պ�����
		//raw��column��������Χ��Сһ�㣬�������Լ��������������̱�Ե�Ͳ�������
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
	//���濪ʼ�ݹ�
	*/
	//printf("floor = %d\nFLOOR - floor = %d\n.", floor, FLOOR - floor);
	//������ײ��

	
	if (floor != 0)
	{
		if (my_turn)
		{
			//�Ƚ����ȵ���Щ���ҵ����ݹ�
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
			{//������������壬ֱ������
				coordinate[0] = priority[0][0][0];
				coordinate[1] = priority[0][0][1];
				best_score = evaluation(board, step_count, my_turn, priority[0][0][0], priority[0][0][1]);
				return best_score;
			}
			if (!final_hit && (FLOOR == floor))
			{//������ֶԷ������γ����壬�����Լ�û�����壬�Ͻ�����ȥ
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
								//���������㣬��¼��ʱ����
							{
								best_coordinate[0] = raw;
								best_coordinate[1] = column;
							}
							//�����֦���޸�
							else
							{
								if (best_score > best_score_of_upper[floor])//��֦
								{
									strncpy(board[raw][column], temp_blank, 2);
									return 89999900;
								}
							}
						}
						//��ԭ
						strncpy(board[raw][column], temp_blank, 2);
						best_score_of_upper[floor - 1] = best_score;
					}
				}

				


			}
			//��������ȫ�������̵�ѭ���ȷ�����
			/*
			for (int raw = 0; raw < 15; raw++)
			{
				for (int column = 1; column < 16; column++)
				{//ÿһ�������ӣ������ӽڵ㣬���ʵ����ÿһ���㶼�����255���ӽڵ�
					//��
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
								//���������㣬��¼��ʱ����
							{
								best_coordinate[0] = raw;
								best_coordinate[1] = column;
							}
							//�����֦���޸�
							else
							{
								if (best_score > best_score_of_upper[floor])//��֦
								{
									strncpy(board[raw][column], temp_blank, 2);
									return 89999900;
								}
							}
						}
						//��ԭ
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
							//����û���Ǹ�������ж�����Ķ�������Ϊ������ǲ����ܻ���ִ���min�������

							if (floor == FLOOR)
								//���������㣬��¼��ʱ����
							{
								best_coordinate[0] = raw;
								best_coordinate[1] = column;
							}
							else
							{
								if (best_score < best_score_of_upper[floor])//��֦
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
			
			//�����Ƿ�����ԭ���ı����������̵�ѭ��
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
							//����û���Ǹ�������ж�����Ķ�������Ϊ������ǲ����ܻ���ִ���min�������
						
							if (floor == FLOOR)
								//���������㣬��¼��ʱ����
							{
								best_coordinate[0] = raw;
								best_coordinate[1] = column;
							}
							else
							{
								if (best_score < best_score_of_upper[floor])//��֦
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
	//��ײ��
	else
	{
		long int temp_score1 = 0;
		long int temp_score2 = 0;
		//����ѵĵ�����ֵ
		if (my_turn)
		{
			temp_score = 0;
			//��������ȼ�����֮ǰ�������´պ�����
			//raw��column��������Χ��Сһ�㣬�������Լ��������������̱�Ե�Ͳ�������
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
						if (temp_score > best_score_of_upper[floor])//��֦
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
						if (temp_score < best_score_of_upper[floor])//��֦
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

	//����㣬��Ҫ����һ�����վ�������������
	if ((FLOOR - floor) == 0)
	{
		*coordinate = *best_coordinate;
		*(coordinate + 1) = *(best_coordinate + 1);
		best_score = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
	}



//strncpy(board[best_coordinate[0]][best_coordinate[1]], temp_blank, 2);
	
	
	return best_score;
}
