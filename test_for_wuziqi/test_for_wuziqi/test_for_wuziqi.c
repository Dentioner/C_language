#include<stdio.h>
#include<string.h>

/*
void chess_play(char board[][17][2])
{
	int raw, column;
	char black[2] = "○";
	char white[2] = "●";
	printf("INPUT:\n");
	scanf("%d %d", &raw, &column);
	strncpy(board[raw][column], black, 2);
}
*/


int main()
{
	
/*

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

	char black[2] = "○";
	char white[2] = "●";

	int i,j,k;
	int raw = 2;
	int column = 2;
	strncpy(board[raw][column], black, 2);
//	chess_play(**board);

	for ( i = 0; i < 15; i++)
	{
		for ( j = 0; j < 17; j++)
		{
			for ( k = 0; k < 2; k++)
				putchar(board[i][j][k]);
		}
		putchar('\n');

	}

	if (strncmp(board[raw][column], black, 2)==0||strcmp(board[raw][column], white, 2) == 0)
		printf("error");

	printf("%d", strcmp("ABCD", "ABCD") );
	printf("%d", strcmp(board[raw][column], "●") );
	printf(board[raw][column]);
*/
	/*
	int i;
	int index;
	int index2;
	index = scanf("%d" ,&i);
	printf("index = %d\n", index);
	index2 = (index!=1);
	printf("index2 = %d\n", index2);
	while ((1 >= i || 15 <= i) && (index2))
	{
		printf("error\n");
		fflush(stdin);
		index = scanf("%d" ,&i);
		printf("index = %d\n", index);
		index2 = (index!=1);
		printf("index2 = %d\n", index2);

	}
*/


	char black[2] = "○";
	char white[2] = "●";
	int step_count;
	char* chess;
	scanf("%d", &step_count);

	if (step_count % 2)//如果step数不能整除2的话，就是白子
	{
		chess = white;
	}
	else
	{
		chess = black;
	}

	puts(chess);

	system("pause");

	return 0;

}