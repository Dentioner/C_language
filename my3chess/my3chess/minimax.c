#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#include<time.h>
#include"head.h"

long int Minimax2(char board[][3][3], int step_count,
	bool my_turn, bool ai_first,
	int floor, int coordinate[])
{
	char black[2] = "��";
	char white[2] = "��";
	char temp_blank[2];//���������ԭ���̣��൱�ڻ���һ����
	char *chess;
	char *opponent_chess;

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
	int best_coordinate[2] = { 0,0 };
	long int temp_score = 0;

	if (floor != 0)
	{
		if (my_turn)
		{
			bool initialized = false;//false��ʾbest_score��û�б���ֵ��
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
							//����������ڲ��Ե�ʱ������ģ���ʽʹ�õ�ʱ����Թص�
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

							
								if ((temp_score >= best_score))//����ط�ȥ����(temp_score != 0)���������������Ҳ��Ҫȥ����������Ҫ�ں��������һ������(temp_score = 0)���Ĵ������
								{
									best_score = temp_score;


									if (floor == FLOOR)

									{
										best_coordinate[0] = raw;
										best_coordinate[1] = column;
									}

								}
							}
							//��ԭ
							strncpy(board[raw][column], temp_blank, 2);



						}
					

				}


			}

			//}
		}
		else
		{
			
			bool initialized = false;//false��ʾbest_score��û�б���ֵ��

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


							//����������ڲ��Ե�ʱ������ģ���ʽʹ�õ�ʱ����Թص�
							DrawBoard(board, 15, 0, 2, coordinate, step_count);

							temp_score = Minimax2(board, step_count + 1,
								!my_turn, ai_first,
								floor - 1, coordinate);

							//if ((temp_score != 0) && (best_score == 0))
	//֮���԰������temp_score != 0Ҳ��ȥ��������Ϊ������һ��֦��һ������0��������ô����ֱ�Ӹ���bestscore
	//������һ����ԽСԽ�ã����֮ǰ��0��֦����ȴ������ˣ��ǲ������
	//������������һ�����Ϊ0�ĵ㣬���һ���ѵ��˴��Ϊ100�ĵ㣬��ȻӦ������һ�㴫��0�ֵģ���������������߼��жϣ�����ȥ��100��
	//����ʲô����дҲ���У���Ϊ����и��֣��ڡ�������Сֵ�������������޷���Ϊ����ֵ
								//����Ӧ�ò���״̬���ķ�������������һ��ֵ��ʱ��֤�ḳ��best
							if (!initialized)//��ʼ��best_score

							{
								best_score = temp_score;
								initialized = true;

							}
							else
							{

							
								if ((temp_score <= best_score))//����ط�ȥ����(temp_score != 0)���������������Ҳ��Ҫȥ����������Ҫ�ں��������һ������(temp_score = 0)���Ĵ������
								{
									best_score = temp_score;
									//����û���Ǹ�������ж�����Ķ�������Ϊ������ǲ����ܻ���ִ���min�������

									if (floor == FLOOR)
										//���������㣬��¼��ʱ����
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
	//��ײ��
	else
	{
		long int temp_score1 = 0;
		long int temp_score2 = 0;
		int best_raw = 0;
		int best_column = 1;
		//int floor_vcx = FLOOR_VCX;//�������ɱר��floor
		//int fatal_best_coordinate[2] = { 0,1 };
		//����ѵĵ�����ֵ
		if (my_turn)
		{
			temp_score = 0;
		
			



				//���forѭ����һ��ʼ���еģ���������ɾ��
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
