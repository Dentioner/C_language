#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void auto_play(char board[][3][3], char chess[], char opponent_chess[], int coordinate[])
{


	for (int p = 0; p < 3; p++)
	{
		for (int q = 0; q < 3; q++)
		{
			if ((strncmp(board[p][q], chess, 2) != 0)
				&& (strncmp(board[p][q], opponent_chess, 2) != 0))
			{
				coordinate[0] = p;
				coordinate[1] = q;
			}
		}
	}

}

