#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"

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
	long int best_score_of_upper[FLOOR] = { 89999900 , -89999900 ,89999900 };//��minimax����ļ�֦�õ�
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
			if (my_turn)
			{

				if (step_count > 4)
				{
					value = Minimax2(board, step_count, my_turn, ai_first, floor, coordinate, best_score_of_upper, priority);
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
					}*/
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
	

