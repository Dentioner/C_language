#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"
#include<time.h>
//��ɱ����
//����ĵ�һά�����������
int fatal_priority[6][20][2] =
{
	{
		{0,0},{0,0},{0,0},{0,0},{0,0},//�Լ��Ļ���
		{0,0},{0,0},{0,0},{0,0},{0,0},//����Ļ���
		{0,0},{0,0},{0,0},{0,0},{0,0},//�Լ��ĳ���
		{0,0},{0,0},{0,0},{0,0},{0,0},//����ĳ���
	},
	//��ͬ
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
long int fatal_best_score_of_upper[6] = { -89999900 , 89999900 , -89999900, 89999900 , -89999900, 89999900 };//��minimax����ļ�֦�õ�
bool fatal_not_in_the_same_branch[6] = { true, true, true, true, true, true };
long int fatal_step(char board[][17][2], int step_count,
	bool my_turn, bool ai_first,
	int floor, int coordinate[], long int fatal_best_score_of_upper[], int fatal_priority[][20][2], bool fatal_not_in_the_same_branch[])
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
	


	if (floor != 0)
	{
		if (my_turn)
		{
			//best_score_of_upper[floor] = 0;
			//�Ƚ����ȵ���Щ���ҵ����ݹ�
			final_hit = before_evaluation(board, fatal_priority, floor, step_count, my_turn);
			//�������˫���forѭ�����ڲ��Ե�ʱ������ģ���ʽʹ�õ�ʱ����Թص�
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
			{//������������壬ֱ������
				coordinate[0] = fatal_priority[0][0][0];
				coordinate[1] = fatal_priority[0][0][1];
				best_score = evaluation(board, step_count, my_turn, fatal_priority[0][0][0], fatal_priority[0][0][1]);
				return best_score;
			}
			if (!final_hit && (FLOOR == floor))
			{//������ֶԷ������γ����壬�����Լ�û�����壬�Ͻ�����ȥ
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
				fatal_not_in_the_same_branch[floor - 1] = true;//�ж��Ƿ���ͬһ��֧�У��������֦
				int raw = fatal_priority[FLOOR - floor][a][0];
				int column = fatal_priority[FLOOR - floor][a][1];
				if ((raw != 0) || (column != 0))
				{
					if ((strncmp(board[raw][column], chess, 2) != 0)
						&& (strncmp(board[raw][column], opponent_chess, 2) != 0))
					{
						strncpy(temp_blank, board[raw][column], 2);
						strncpy(board[raw][column], chess, 2);
						//�����������ڲ��Ե�ʱ��ʹ�õģ���ʽʹ�õ�ʱ��ص�
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
								//���������㣬��¼��ʱ����
							{
								best_coordinate[0] = raw;
								best_coordinate[1] = column;
							}
							//�����֦���޸�
							else
							{
								if ((best_score > fatal_best_score_of_upper[floor]) && (fatal_not_in_the_same_branch[floor]))//��֦
								{
									strncpy(board[raw][column], temp_blank, 2);
									return 89999900;
								}

							}
						}
						//��ԭ
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
			//�������˫���forѭ�����ڲ��Ե�ʱ������ģ���ʽʹ�õ�ʱ����Թص�
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
						//����������ڲ��Ե�ʱ������ģ���ʽʹ�õ�ʱ����Թص�
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
							//����û���Ǹ�������ж�����Ķ�������Ϊ������ǲ����ܻ���ִ���min�������

							if (floor == FLOOR)
								//���������㣬��¼��ʱ����
							{
								best_coordinate[0] = raw;
								best_coordinate[1] = column;
							}
							else
							{
								if ((best_score < fatal_best_score_of_upper[floor]) && fatal_not_in_the_same_branch[floor])//��֦
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
	//��ײ��
	else
	{
		long int temp_score1 = 0;
		long int temp_score2 = 0;
		//����ѵĵ�����ֵ
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
							if ((best_score < best_score_of_upper[floor]) && not_in_the_same_branch[floor])//��֦
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
							if ((best_score > best_score_of_upper[floor]) && not_in_the_same_branch[floor])//��֦
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

