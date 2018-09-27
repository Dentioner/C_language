#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include"head.h"

void main()
{
	int step_count = 0; //游戏下了几个子的计数
	bool my_turn = true; //暂时用不上，这个东西是确认这一步是哪一方下子了
	bool continue_playing = true; //确认游戏是否继续
	long int value = 0;//评分函数的打分
	long int my_value = 0;//我方得分
	long int opponent_value = 0;//对方得分
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
	while (continue_playing)
	{
		//在这个循环里面试着将评分函数混进去
		//首先尝试着将自己下的每一步用评分函数打个分吧
		DrawBoard(board, 15, value);
		//chess_play(board, step_count);老的chessplay函数
		get_coordinate(coordinate, board, step_count);
		chess_play_ver2(board, step_count, coordinate);
		//value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
		my_value = evaluation(board, step_count, my_turn, coordinate[0], coordinate[1]);
		opponent_value = evaluation(board, step_count + 1, !my_turn, coordinate[0], coordinate[1]);
		value = my_value + opponent_value;
		//上面这个分开打分的可能有问题
		continue_playing = judgement(board, step_count);
		my_turn = !my_turn;
		step_count++;
	}
	DrawBoard(board, 15, value);
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

void DrawBoard(char board[][17][2], int i, long int value)
{
	system("cls");   //清屏
	printf("  ==Welcome to FiveInRow Game==\n\n\n");

	

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