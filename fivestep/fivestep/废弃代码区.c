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
