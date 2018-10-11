#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include"head.h"
#include<time.h>
#include<stdlib.h>

void Zobrist()
{
	int zob_raw, zob_column, zob_status;
	long long int a, b, c;
	srand(time(NULL));
	long long int Zobrist_sheet[15][15][3] = {0};
	for (zob_raw = 0; zob_raw < 15; zob_raw++)
	{
		for (zob_column = 0; zob_column < 15; zob_column++)
		{
			for (zob_status = 0; zob_status < 3; zob_status++)
			{
				a = rand();
				b = rand();
				c = rand();
				Zobrist_sheet[zob_raw][zob_column][zob_status] = a * 10000 + b * 1000 + c;
				printf("%lld ", Zobrist_sheet[zob_raw][zob_column][zob_status]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
}