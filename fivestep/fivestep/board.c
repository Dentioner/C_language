#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"

//注意写好之后要按照老师给的规范进行优化，见五子棋规则的doc文件
void main()
{
	int step_count = 0; //游戏下了几个子的计数
	bool my_turn = true; //暂时用不上，这个东西是确认这一步是哪一方下子了
	bool continue_playing = true; //确认游戏是否继续
	bool ai_first = false;//默认电脑后走
	bool invalid_mode = true;
	long int value = 0;//评分函数的打分
	long int my_value = 0;//我方得分
	long int opponent_value = 0;//对方得分
	long int best_score_of_upper[FLOOR] = { 89999900 , -89999900 ,89999900 };//给minimax里面的剪枝用的
	int mode_choice;
	int mode_choice_index;


	char board[15][17][2] =
	{
		{"15","┏","┯","┯","┯","┯","┯","┯","┯","┯","┯","┯","┯","┯","┯","┓","15"},
		{"14","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","14"},
		{"13","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","13"},
		{"12","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","12"},
		{"11","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","11"},
		{"10","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","10"},
		{"9","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","9"},
		{"8","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","8"},
		{"7","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","7"},
		{"6","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","6"},
		{"5","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","5"},
		{"4","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","4"},
		{"3","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","3"},
		{"2","┠","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┼","┨","2"},
		{"1","┗","┷","┷","┷","┷","┷","┷","┷","┷","┷","┷","┷","┷","┷","┛","1"}

	};

	int coordinate[2] = { 0, 0 };
	char black[2] = "○";
	char white[2] = "●";

	//这里准备写一个判断是PVP还是PVE的语句
		//如果是PVE，选择黑子还是白子
	printf("************************************************\n");
	printf("请选择模式\n");
	printf("1.pvp\t\t2.pve\n");
	printf("************************************************\n");
	while (invalid_mode)
	{

		mode_choice_index = scanf("%d", &mode_choice);
		while (getchar() != '\n')
			continue;
		if (mode_choice_index != 1)
		{
			printf("无效输入，请重试\n");

			continue;
		}
		if ((mode_choice != 1) && (mode_choice != 2))
		{
			printf("无效输入，请重试\n");

			continue;
		}

		invalid_mode = false;
	}

	if (mode_choice == 1)
	{

		while (continue_playing)
		{
			//在这个循环里面试着将评分函数混进去
			//首先尝试着将自己下的每一步用评分函数打个分吧
			DrawBoard(board, 15, value, mode_choice);
			//chess_play(board, step_count);老的chessplay函数
			get_coordinate(coordinate, board, step_count);
			chess_play_ver2(board, step_count, coordinate);
			value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
			//my_value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
			//opponent_value = evaluation(board, step_count + 1, !my_turn, coordinate[0], coordinate[1]);
			//value = my_value + opponent_value;
			//上面这个分开打分的可能有问题
			continue_playing = judgement(board, step_count);
			my_turn = !my_turn;
			step_count++;
		}
		DrawBoard(board, 15, value, mode_choice);
		if (step_count % 2)
		{
			printf("黑子获胜");
		}
		else
		{
			printf("白子获胜");
		}

		return;
	}


	else
	{
		//PVE
		
		printf("电脑先手还是对方先手？\n");
		printf("1.电脑先手\t\t2.对方先手\n");
		printf("************************************************\n");
		int ai_choice = 0;
		int ai_choice_index = 0;
		int floor = FLOOR;//搜索层数
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
				printf("无效输入，请重试\n");

				continue;
			}
			if ((ai_choice != 1) && (ai_choice != 2))
			{
				printf("无效输入，请重试\n");

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
			//注意这里无需将my_turn求反了，在αβ剪枝函数中已经做了
			int priority[4][26][2] =
			{
				{
					{0,0},{0,0},//连五
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//活四
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//双活三
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//冲四
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//连三
				},

				{
					{0,0},{0,0},//连五
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//活四
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//双活三
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//冲四
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//连三
				},

				{
					{0,0},{0,0},//连五
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//活四
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//双活三
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//冲四
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//连三
				},

				{
					{0,0},{0,0},//连五
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//活四
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//双活三
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//冲四
					{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},//连三
				}
			};//连五双方只需要1个，连四、双活三、冲四、活三均给三组坐标（暂定）
			//第一层数组表示的是，minimax函数搜索的层数，每一层用一个本维度的数组
			//第二层数组从左到右依次对应的坐标是：
			//我方连五，对方连五，我方（双）活四，对方（双）活四（这个规则可能需要进一步细分）
			//我方双活三，对方双活三，我方冲四，对方冲四，我方活三，对方活三
			//第三层就是横纵坐标了
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
			printf("黑子获胜");
		}
		else
		{
			printf("白子获胜");
		}

		return;
		

		printf("施工中\n");
		
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
	system("cls");   //清屏
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
	

