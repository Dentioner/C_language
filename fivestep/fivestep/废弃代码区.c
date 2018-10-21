#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include"head.h"
/*
//ע��д��֮��Ҫ������ʦ���Ĺ淶�����Ż���������������doc�ļ�
void main()
{
	int step_count = 0; //��Ϸ���˼����ӵļ���
	bool my_turn = true; //��ʱ�ò��ϣ����������ȷ����һ������һ��������
	bool continue_playing = true; //ȷ����Ϸ�Ƿ����
	bool ai_first = false;//Ĭ�ϵ��Ժ���
	bool invalid_mode = true;
	long int value = 0;//���ֺ����Ĵ��
	long int my_value = 0;//�ҷ��÷�
	long int opponent_value = 0;//�Է��÷�
	int mode_choice;
	int mode_choice_index;
	char board[15][17][2] =
	{
		{"15","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","15"},
		{"14","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","14"},
		{"13","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","13"},
		{"12","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","12"},
		{"11","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","11"},
		{"10","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","10"},
		{"9","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","9"},
		{"8","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","8"},
		{"7","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","7"},
		{"6","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","6"},
		{"5","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","5"},
		{"4","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","4"},
		{"3","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","3"},
		{"2","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","2"},
		{"1","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","1"}

	};

	int coordinate[2] = { 0, 0 };
	char black[2] = "��";
	char white[2] = "��";
	//����׼��дһ���ж���PVP����PVE�����
		//�����PVE��ѡ����ӻ��ǰ���
	printf("************************************************\n");
	printf("��ѡ��ģʽ\n");
	printf("1.pvp\t\t2.pve\n");
	printf("************************************************\n");
	while (invalid_mode)
	{

		mode_choice_index = scanf("%d", &mode_choice);
		while (getchar() != '\n')
			continue;
		if (mode_choice_index != 1)
		{
			printf("��Ч���룬������\n");

			continue;
		}
		if ((mode_choice != 1) && (mode_choice != 2))
		{
			printf("��Ч���룬������\n");

			continue;
		}

		invalid_mode = false;
	}

	if (mode_choice == 1)
	{

		while (continue_playing)
		{
			//�����ѭ���������Ž����ֺ������ȥ
			//���ȳ����Ž��Լ��µ�ÿһ�������ֺ�������ְ�
			DrawBoard(board, 15, value, mode_choice);
			//chess_play(board, step_count);�ϵ�chessplay����
			get_coordinate(coordinate, board, step_count);
			chess_play_ver2(board, step_count, coordinate);
			value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
			//my_value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
			//opponent_value = evaluation(board, step_count + 1, !my_turn, coordinate[0], coordinate[1]);
			//value = my_value + opponent_value;
			//��������ֿ���ֵĿ���������
			continue_playing = judgement(board, step_count);
			my_turn = !my_turn;
			step_count++;
		}
		DrawBoard(board, 15, value, mode_choice);
		if (step_count % 2)
		{
			printf("���ӻ�ʤ");
		}
		else
		{
			printf("���ӻ�ʤ");
		}

		return;
	}


	else
	{
		//PVE

		printf("�������ֻ��ǶԷ����֣�\n");
		printf("1.��������\t\t2.�Է�����\n");
		printf("************************************************\n");
		int ai_choice = 0;
		int ai_choice_index = 0;
		int floor = FLOOR;//��������
		char *chess;
		char *opponent_chess;
		bool invalid_ai_choice = true;
		while (invalid_ai_choice)
		{
			ai_choice_index = scanf("%d", &ai_choice);
			while (getchar() != '\n')
				continue;
			if (ai_choice_index != 1)
			{
				printf("��Ч���룬������\n");

				continue;
			}
			if ((ai_choice != 1) && (ai_choice != 2))
			{
				printf("��Ч���룬������\n");

				continue;
			}

			invalid_ai_choice = false;
		}

		if (ai_choice == 1)
		{
			ai_first = true;
		}
		else
		{
			ai_first = false;
		}

		if (ai_first)
		{
			my_turn = true;
			chess = black;
			opponent_chess = white;
			strncpy(board[8][7], chess, 2);
		}
		else
		{
			my_turn = false;
			chess = white;
			opponent_chess = black;

		}
		while (continue_playing)
		{
			DrawBoard(board, 15, value, mode_choice);
			//ע���������轫my_turn���ˣ��ڦ��¼�֦�������Ѿ�����
			if (my_turn)
			{

				if (step_count > 4)
				{
					value = Minimax2(board, step_count, my_turn, ai_first, floor, coordinate);
					chess_play_ver2(board, step_count, coordinate);
				}
				else
				{
					for (int p = 0; p < 15; p++)
					{
						for (int q = 0; q < 17; q++)
						{
							if ((strncmp(board[p][q], opponent_chess, 2)) == 0)
							{
								if (((strncmp(board[p + 1][q], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p + 1][q], chess, 2)) != 0))
								{
									strncpy(board[p + 1][q], chess, 2);
								}

								else if (((strncmp(board[p][q + 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p][q + 1], chess, 2)) != 0))
								{
									strncpy(board[p][q + 1], chess, 2);
								}
								else if (((strncmp(board[p - 1][q], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p - 1][q], chess, 2)) != 0))
								{
									strncpy(board[p - 1][q], chess, 2);
								}
								else if (((strncmp(board[p][q - 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p][q - 1], chess, 2)) != 0))
								{
									strncpy(board[p][q - 1], chess, 2);
								}
								else if (((strncmp(board[p - 1][q - 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p - 1][q - 1], chess, 2)) != 0))
								{
									strncpy(board[p - 1][q - 1], chess, 2);
								}
								else if (((strncmp(board[p - 1][q + 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p - 1][q + 1], chess, 2)) != 0))
								{
									strncpy(board[p - 1][q + 1], chess, 2);
								}
								else if (((strncmp(board[p + 1][q + 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p + 1][q + 1], chess, 2)) != 0))
								{
									strncpy(board[p + 1][q + 1], chess, 2);
								}
								else if (((strncmp(board[p + 1][q - 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p + 1][q - 1], chess, 2)) != 0))
								{
									strncpy(board[p + 1][q - 1], chess, 2);
								}

							}
						}
					}
				}
			}
			else
			{
				get_coordinate(coordinate, board, step_count);
				chess_play_ver2(board, step_count, coordinate);
				value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
			}

			continue_playing = judgement(board, step_count);
			my_turn = !my_turn;
			step_count++;
		}
		DrawBoard(board, 15, value, mode_choice);
		if (step_count % 2)
		{
			printf("���ӻ�ʤ");
		}
		else
		{
			printf("���ӻ�ʤ");
		}

		return;


		printf("ʩ����\n");

	}

}

void DrawBoard(char board[][17][2], int i, long int value, int mode_choice)
{
	char *mode;
	if (mode_choice == 1)
	{
		mode = "PVP";
	}
	else
	{
		mode = "PVE";
	}
	system("cls");   //����
	printf("  ==Welcome to FiveInRow Game==\n");
	printf("          ==%s mode==\n\n", mode);



	printf("   A B C D E F G H I J K L M N O \n");



	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			for (int k = 0; k < 2; k++)
				putchar(board[i][j][k]);
		}
		putchar('\n');
	}
	printf("   A B C D E F G H I J K L M N O \n");
	//system("pause");
	printf("value = %ld\n", value);

}



*/

/*
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include"head.h"
//����ʽ�������������ȼ�˳�򣬶Է�֧����������߼�֦�ٶ�
//��https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js
bool before_evaluation(char board[][17][2], int priority[][10][2], int floor,
	int step_count, bool my_turn)
	//step_count�������ļ����β���������evaluation��
{
	int my_raw = 0;
	int my_column = 0;
	char black[2] = "��";
	char white[2] = "��";
	long int my_value = 0;
	long int opponent_value = 0;
	bool get_coordinate1 = false;
	bool get_coordinate2 = false;
	bool get_coordinate3 = false;
	bool get_coordinate4 = false;
	bool get_coordinate5 = false;
	bool get_coordinate6 = false;
	bool get_coordinate7 = false;
	bool get_coordinate8 = false;
	bool get_coordinate9 = false;
	bool get_coordinate10 = false;
	bool final_hit = false;//�����ҷ�����ֱ�ӷ���
	for (my_raw = 0; my_raw < 15; my_raw++)
	{
		for (my_column = 1; my_column < 16; my_column++)
		{

			if ((strncmp(board[my_raw][my_column], black, 2) != 0)
				&& (strncmp(board[my_raw][my_column], white, 2) != 0))
			{
				my_value = evaluation(board, step_count, my_turn, my_raw, my_column);
				opponent_value = evaluation(board, step_count + 1, !my_turn, my_raw, my_column);
				if (my_value >= Consecutive_Five)//����������ҷ�����ĵط�
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						final_hit = true;
						return final_hit;
					}
					final_hit = true;
					return final_hit;

				}
				else if (opponent_value <= -Consecutive_Five)//��������˶Է�����ĵط�
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						return final_hit;
					}
				}
				else if (my_value >= Open_Four)
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						return final_hit;
					}
				}
				else if (opponent_value <= -Open_Four)
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						return final_hit;
					}
				}
				else if (my_value >= 2 * Open_Three)
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						return final_hit;
					}
				}
				else if (opponent_value <= -2 * Open_Three)
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						return final_hit;
					}
				}
				else if (my_value >= Capped_Four)
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						return final_hit;
					}
				}
				else if (opponent_value <= -Capped_Four)
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						return final_hit;
					}
				}
				else if (my_value >= Open_Three)
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						return final_hit;
					}
				}
				else if (opponent_value <= -Open_Three)
				{
					if (!get_coordinate1)//�����һ��λ���ǿյ�
					{

						priority[FLOOR - floor][0][0] = my_raw;
						priority[FLOOR - floor][0][1] = my_column;
						get_coordinate1 = true;
					}
					else if (!get_coordinate2)//����ڶ���λ���ǿյ�
					{

						priority[FLOOR - floor][1][0] = my_raw;
						priority[FLOOR - floor][1][1] = my_column;
						get_coordinate2 = true;
					}
					else if (!get_coordinate3)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][2][0] = my_raw;
						priority[FLOOR - floor][2][1] = my_column;
						get_coordinate3 = true;
					}
					else if (!get_coordinate4)//������ĸ�λ���ǿյ�
					{

						priority[FLOOR - floor][3][0] = my_raw;
						priority[FLOOR - floor][3][1] = my_column;
						get_coordinate4 = true;
					}
					else if (!get_coordinate5)//��������λ���ǿյ�
					{

						priority[FLOOR - floor][4][0] = my_raw;
						priority[FLOOR - floor][4][1] = my_column;
						get_coordinate5 = true;
					}
					else if (!get_coordinate6)//���������λ���ǿյ�
					{

						priority[FLOOR - floor][5][0] = my_raw;
						priority[FLOOR - floor][5][1] = my_column;
						get_coordinate6 = true;
					}
					else if (!get_coordinate7)//������߸�λ���ǿյ�
					{

						priority[FLOOR - floor][6][0] = my_raw;
						priority[FLOOR - floor][6][1] = my_column;
						get_coordinate7 = true;
					}
					else if (!get_coordinate8)//����ڰ˸�λ���ǿյ�
					{

						priority[FLOOR - floor][7][0] = my_raw;
						priority[FLOOR - floor][7][1] = my_column;
						get_coordinate8 = true;
					}
					else if (!get_coordinate9)//����ھŸ�λ���ǿյ�
					{

						priority[FLOOR - floor][8][0] = my_raw;
						priority[FLOOR - floor][8][1] = my_column;
						get_coordinate9 = true;
					}
					else if (!get_coordinate10)//�����ʮ��λ���ǿյ�
					{

						priority[FLOOR - floor][9][0] = my_raw;
						priority[FLOOR - floor][9][1] = my_column;
						get_coordinate10 = true;
						return final_hit;
					}
				}

			}

			if (get_coordinate1
				&& get_coordinate2
				&& get_coordinate3
				&& get_coordinate4
				&& get_coordinate5
				&& get_coordinate6
				&& get_coordinate7
				&& get_coordinate8
				&& get_coordinate9
				&& get_coordinate10)
			{
				return final_hit;
			}

		}




	}
	return final_hit;
}
*/


/*
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

}


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
	
	//printf("floor = %d\nFLOOR - floor = %d\n.", floor, FLOOR - floor);
	//������ײ��


	if (floor != 0)
	{
		if (my_turn)
		{
			//best_score_of_upper[floor] = 0;
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
				&& (FLOOR == floor))
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
						if (best_score < best_score_of_upper[floor - 1])
						{
							best_score_of_upper[floor - 1] = best_score;
						}

					}
				}




			}
			//��������ȫ�������̵�ѭ���ȷ�����
			
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
			}

		}
		else
		{
			//best_score_of_upper[floor] = 0;
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
						if (best_score > best_score_of_upper[floor - 1])
						{
							best_score_of_upper[floor - 1] = best_score;
						}

					}
				}

			}

			//�����Ƿ�����ԭ���ı����������̵�ѭ��
			
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
*/


/*
if (mode_choice == 1)
{
	DrawBoard(board, 15, value, mode_choice, coordinate, -1);
	while (continue_playing)
	{
		//�����ѭ���������Ž����ֺ������ȥ
		//���ȳ����Ž��Լ��µ�ÿһ�������ֺ�������ְ�



		//chess_play(board, step_count);�ϵ�chessplay����
		get_coordinate(coordinate, board, step_count);
		chess_play_ver2(board, step_count, coordinate);
		value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
		//my_value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
		//opponent_value = evaluation(board, step_count + 1, !my_turn, coordinate[0], coordinate[1]);
		//value = my_value + opponent_value;
		//��������ֿ���ֵĿ���������
		DrawBoard(board, 15, value, mode_choice, coordinate, step_count);


		return_to_normal_chess(board, step_count, coordinate, coordinate);

		continue_playing = judgement(board, step_count);
		my_turn = !my_turn;
		step_count++;
	}
	DrawBoard(board, 15, value, mode_choice, coordinate, step_count);
	if (step_count % 2)
	{
		printf("���ӻ�ʤ");
	}
	else
	{
		printf("���ӻ�ʤ");
	}

	return;
}
*/


/*
else
	{
		//PVE

		printf("�������ֻ��ǶԷ����֣�\n");
		printf("1.��������\t\t2.�Է�����\n");
		printf("************************************************\n");
		int ai_choice = 0;
		int ai_choice_index = 0;
		int floor = FLOOR;//��������
		char *chess;
		char *opponent_chess;
		bool invalid_ai_choice = true;
		while (invalid_ai_choice)
		{
			ai_choice_index = scanf("%d", &ai_choice);
			while (getchar() != '\n')
				continue;
			if (ai_choice_index != 1)
			{
				printf("��Ч���룬������\n");

				continue;
			}
			if ((ai_choice != 1) && (ai_choice != 2))
			{
				printf("��Ч���룬������\n");

				continue;
			}

			invalid_ai_choice = false;
		}

		if (ai_choice == 1)
		{
			ai_first = true;
		}
		else
		{
			ai_first = false;
		}

		if (ai_first)
		{
			my_turn = true;
			chess = black;
			opponent_chess = white;
			strncpy(board[7][8], chess, 2);
		}
		else
		{
			my_turn = false;
			chess = white;
			opponent_chess = black;

		}
		while (continue_playing)
		{
			DrawBoard(board, 15, value, mode_choice, coordinate, step_count);
			//ע���������轫my_turn���ˣ��ڦ��¼�֦�������Ѿ�����
			int priority[4][26][2] =
			{
				{
					{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//˫����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
				},

				{
					{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//˫����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
				},

				{
					{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//˫����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
				},

				{
					{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//˫����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//����
				}
			};//����˫��ֻ��Ҫ1�������ġ�˫���������ġ����������������꣨�ݶ���
			//��һ�������ʾ���ǣ�minimax���������Ĳ�����ÿһ����һ����ά�ȵ�����
			//�ڶ���������������ζ�Ӧ�������ǣ�
			//�ҷ����壬�Է����壬�ҷ���˫�����ģ��Է���˫�����ģ�������������Ҫ��һ��ϸ�֣�
			//�ҷ�˫�������Է�˫�������ҷ����ģ��Է����ģ��ҷ��������Է�����
			//��������Ǻ���������
			long int best_score_of_upper[FLOOR] = { -89999900 , 89999900 , -89999900 };//��minimax����ļ�֦�õ�
			bool not_in_the_same_branch[FLOOR] = { true, true, true };
			if (my_turn)
			{

				if (step_count > 4)
				{
					value = Minimax2(board, step_count, my_turn, ai_first, floor, coordinate, best_score_of_upper, priority, not_in_the_same_branch);
					if ((coordinate[0] == 0) && (coordinate[1] == 1))
					{
						auto_play(board, chess, opponent_chess);
					}
					else
					{
						chess_play_ver2(board, step_count, coordinate);
					}

				}
				else
				{
					auto_play(board, chess, opponent_chess);
					/*for (int p = 0; p < 15; p++)
					{
						for (int q = 0; q < 17; q++)
						{
							if ((strncmp(board[p][q], opponent_chess, 2)) == 0)
							{
								if (((strncmp(board[p + 1][q], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p + 1][q], chess, 2)) != 0))
								{
									strncpy(board[p + 1][q], chess, 2);

								}
								else if (((strncmp(board[p][q + 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p][q + 1], chess, 2)) != 0))
								{
									strncpy(board[p][q + 1], chess, 2);
								}
								else if (((strncmp(board[p - 1][q], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p - 1][q], chess, 2)) != 0))
								{
									strncpy(board[p - 1][q], chess, 2);
								}
								else if (((strncmp(board[p][q - 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p][q - 1], chess, 2)) != 0))
								{
									strncpy(board[p][q - 1], chess, 2);
								}
								else if (((strncmp(board[p - 1][q - 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p - 1][q - 1], chess, 2)) != 0))
								{
									strncpy(board[p - 1][q - 1], chess, 2);
								}
								else if (((strncmp(board[p - 1][q + 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p - 1][q + 1], chess, 2)) != 0))
								{
									strncpy(board[p - 1][q + 1], chess, 2);
								}
								else if (((strncmp(board[p + 1][q + 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p + 1][q + 1], chess, 2)) != 0))
								{
									strncpy(board[p + 1][q + 1], chess, 2);
								}
								else if (((strncmp(board[p + 1][q - 1], opponent_chess, 2)) != 0)
									&& ((strncmp(board[p + 1][q - 1], chess, 2)) != 0))
								{
									strncpy(board[p + 1][q - 1], chess, 2);
								}
							}
						}
					}
				}
			}
			else
			{
			get_coordinate(coordinate, board, step_count);
			chess_play_ver2(board, step_count, coordinate);
			value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
			}

			continue_playing = judgement(board, step_count);
			my_turn = !my_turn;
			step_count++;
		}
		DrawBoard(board, 15, value, mode_choice, coordinate, step_count);
		if (step_count % 2)
		{
			printf("���ӻ�ʤ");
		}
		else
		{
			printf("���ӻ�ʤ");
		}

		return;


		printf("ʩ����\n");

*/



/*
	else
	{
	long int temp_score1 = 0;
	long int temp_score2 = 0;
	int best_raw = 0;
	int best_column = 1;
	//����ѵĵ�����ֵ
	if (my_turn)
	{
		temp_score = 0;
		//best_score_of_upper[floor] = 0;
		//��������ϣ������оͲ������
		temp_score1 = Zobrist_hashing(hashing_value, key, best_raw, best_column, false, step_count, board, my_turn, hashing_value_now);
		temp_score2 = Zobrist_hashing(hashing_value, key, best_raw, best_column, false, step_count + 1, board, !my_turn, hashing_value_now);
		if (temp_score1 == 0 && temp_score2 == 0)
		{//�����ϣ��û��ֵ
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
								best_raw = raw;
								best_column = column;

							}
							if (temp_score > best_score)
							{
								best_score = temp_score;
								best_raw = raw;
								best_column = column;
								//best_coordinate[0] = raw;
									//best_coordinate[1] = column;
							}
							/*
							if ((best_score < best_score_of_upper[floor]) && not_in_the_same_branch[floor])//��֦
							{

								return -89999900;
							}
							*//*
						}
					}
				}
			}


			//��ѭ�������󣬽���ѵ������������ϣ������
			Zobrist_hashing(hashing_value, key, best_raw, best_column, true, step_count, board, my_turn, hashing_value_now);



		}*/
		/*
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
							best_raw = raw;
							best_column = column;

						}
						if (temp_score > best_score)
						{
							best_score = temp_score;
							best_raw = raw;
							best_column = column;
							//best_coordinate[0] = raw;
								//best_coordinate[1] = column;
						}
						/*
						if ((best_score < best_score_of_upper[floor]) && not_in_the_same_branch[floor])//��֦
						{

							return -89999900;
						}
						*/

		/*
		else
		{
			best_score = temp_score1 + temp_score2;
		}






	}
	else
	{
		temp_score = 0;
		temp_score1 = Zobrist_hashing(hashing_value, key, best_raw, best_column, false, step_count, board, my_turn, hashing_value_now);
		temp_score2 = Zobrist_hashing(hashing_value, key, best_raw, best_column, false, step_count + 1, board, !my_turn, hashing_value_now);
		if (temp_score1 == 0 && temp_score2 == 0)
		{


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
							/*
							if ((best_score > best_score_of_upper[floor]) && not_in_the_same_branch[floor])//��֦
							{

								return 89999900;
							}
							*/
		/*
						}
					}

				}
			}

			//��ѭ�������󣬽���ѵ������������ϣ������
			Zobrist_hashing(hashing_value, key, best_raw, best_column, true, step_count, board, my_turn, hashing_value_now);



		}
		else
		{
			best_score = temp_score1 + temp_score2;
		}

	}
	}
	*/