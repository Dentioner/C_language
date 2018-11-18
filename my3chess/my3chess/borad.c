#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"
#include<time.h>

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

	int mode_choice;
	int mode_choice_index;


	char board[3][3][3] =
	{
		{"┏","┯","┓"},
		{"┠","┼","┨"},
		{"┗","┷","┛"}

	};

	int coordinate[2] = { 0, 0 };
	char black[3] = "○";
	char white[3] = "●";
	char roaming[3] = "△";//随便定义的一个，这个是用来记录上一步的空格在哪个位置，便于悔棋

	
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
		printf("No\n");

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
			strncpy(board[2][2], chess, 2);
			my_turn = false;
			step_count++;
		}
		else
		{
			my_turn = false;
			chess = white;
			opponent_chess = black;

		}
		DrawBoard(board, 15, value, mode_choice, coordinate, -1);
		while (continue_playing)
		{
			long int best_score_of_upper[11] = { -89999900 , 89999900 , -89999900, 89999900 , -89999900, 89999900, -89999900 , 89999900 , -89999900, 89999900, -89999900 };//给minimax里面的剪枝用的
			//注意上下这两个数组的编号问题。floor是从11往0递归的，因此要保持最后一个元素不变。
			bool not_in_the_same_branch[11] = { true, true, true, true, true, true, true, true, true, true, true };

			if (my_turn)
			{
				double start_time = clock();
				double end_time, cost_time;
				if (step_count > 2)
				{
					value = Minimax2(board, step_count, my_turn, ai_first, floor, coordinate, best_score_of_upper, not_in_the_same_branch);
					/*if ((coordinate[0] == 0) && (coordinate[1] == 0))
					{
						auto_play(board, chess, opponent_chess, coordinate);
						chess_play_ver2(board, step_count, coordinate);
						DrawBoard(board, 15, value, mode_choice, coordinate, step_count);
						return_to_normal_chess(board, step_count, coordinate, coordinate);
					}
					else*/
					//{
						chess_play_ver2(board, step_count, coordinate);
						DrawBoard(board, 15, value, mode_choice, coordinate, step_count);
						return_to_normal_chess(board, step_count, coordinate, coordinate);
					//}

				}
				else
				{
					auto_play(board, chess, opponent_chess, coordinate);
					chess_play_ver2(board, step_count, coordinate);
					DrawBoard(board, 15, value, mode_choice, coordinate, step_count);
					return_to_normal_chess(board, step_count, coordinate, coordinate);
					
				}
				end_time = clock();
				cost_time = (end_time - start_time) / CLK_TCK;
				printf("time=%fs.\n", cost_time);
				
			}
			else
			{
				get_coordinate(coordinate, board, step_count);
				
				strncpy(roaming, board[coordinate[0]][coordinate[1]], 2);//记录上一步的状态
				value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
				chess_play_ver2(board, step_count, coordinate);
				DrawBoard(board, 15, value, mode_choice, coordinate, step_count);
				return_to_normal_chess(board, step_count, coordinate, coordinate);
				//下面是悔棋代码，可能会有问题			
				printf("是否想要悔棋？按y悔棋，按别的任意键正常继续游戏.\n");
				char c_getback = ' ';
				c_getback = getchar();
				while (getchar() != '\n')
					continue;
				int i_getback = c_getback;
				if (i_getback == 89 || i_getback == 121)
				{
					strncpy(board[coordinate[0]][coordinate[1]], roaming, 2);
					DrawBoard(board, 15, value, mode_choice, coordinate, step_count);
					continue;
				}

			}

			continue_playing = judgement(board, step_count);
			my_turn = !my_turn;
			step_count++;
		}
		DrawBoard(board, 15, value, mode_choice, coordinate, step_count);
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

}

void DrawBoard(char board[][3][3], int i, long int value, int mode_choice, int coordinate[], int step_count)
{
	char c_column;
	int i_raw;
	i_raw = 15 - coordinate[0];
	c_column = 64 + coordinate[1];
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







	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
				putchar(board[i][j][k]);
		}
		putchar('\n');
	}
	
	//system("pause");
	if (step_count != -1)
	{
		printf("最后落子(%d, %c), value = %ld\n", i_raw, c_column, value);
	}


}
