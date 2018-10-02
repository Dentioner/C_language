#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void auto_play(char board[][17][2], char chess[], char opponent_chess[])
{


	for (int p = 0; p < 15; p++)
	{
		for (int q = 0; q < 17; q++)
		{
			if ((strncmp(board[p][q], opponent_chess, 2)) == 0)
			{
				if (((strncmp(board[p + 1][q], opponent_chess, 2)) != 0)
					&& ((strncmp(board[p + 1][q], chess, 2)) != 0)
					&&(p+1<=14))
				{
					strncpy(board[p + 1][q], chess, 2);
					return;
				}

				else if (((strncmp(board[p][q + 1], opponent_chess, 2)) != 0)
					&& ((strncmp(board[p][q + 1], chess, 2)) != 0)
					&&(q+1<=15))
				{
					strncpy(board[p][q + 1], chess, 2);
					return;
				}
				else if (((strncmp(board[p - 1][q], opponent_chess, 2)) != 0)
					&& ((strncmp(board[p - 1][q], chess, 2)) != 0)
					&&(p-1>=0))
				{
					strncpy(board[p - 1][q], chess, 2);
					return;
				}
				else if (((strncmp(board[p][q - 1], opponent_chess, 2)) != 0)
					&& ((strncmp(board[p][q - 1], chess, 2)) != 0)
					&&(q-1>=0))
				{
					strncpy(board[p][q - 1], chess, 2);
					return;
				}
				else if (((strncmp(board[p - 1][q - 1], opponent_chess, 2)) != 0)
					&& ((strncmp(board[p - 1][q - 1], chess, 2)) != 0)
					&&(p-1>=0)
					&&(q-1>=0))
				{
					strncpy(board[p - 1][q - 1], chess, 2);
					return;
				}
				else if (((strncmp(board[p - 1][q + 1], opponent_chess, 2)) != 0)
					&& ((strncmp(board[p - 1][q + 1], chess, 2)) != 0)
					&&(p-1>=0)
					&&(q+1<=15))
				{
					strncpy(board[p - 1][q + 1], chess, 2);
					return;
				}
				else if (((strncmp(board[p + 1][q + 1], opponent_chess, 2)) != 0)
					&& ((strncmp(board[p + 1][q + 1], chess, 2)) != 0)
					&&(p+1<=14)
					&&(q+1<=15))
				{
					strncpy(board[p + 1][q + 1], chess, 2);
					return;
				}
				else if (((strncmp(board[p + 1][q - 1], opponent_chess, 2)) != 0)
					&& ((strncmp(board[p + 1][q - 1], chess, 2)) != 0)
					&&(p+1<=14)
					&&(q-1>=0))
				{
					strncpy(board[p + 1][q - 1], chess, 2);
					return;
				}

			}
		}
}

}

//此函数用于防止ai自杀，落在奇怪的位置上面
//此函数待优化，目前用了反而会让ai自杀
bool verify_coordinate(char board[][17][2], int raw, int column, 
	char chess, char opponent_chess)
{
	char black[2] = "○";
	char white[2] = "●";
	bool valid_coordinate = false;
	if ((strncmp(board[raw][column], black, 2)!=0)
		&& (strncmp(board[raw][column], white, 2) != 0))
	{
		valid_coordinate = true;
	}
	return valid_coordinate;
}