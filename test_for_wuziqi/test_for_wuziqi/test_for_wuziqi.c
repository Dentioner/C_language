#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define bool int
#define true 1
#define false 0
#define FLOOR 3

int main()
{
	int zob_raw, zob_column, zob_status;
	srand(time(NULL));

	long long int Zobrist_sheet[15][15][3] = {0};
	for (zob_raw = 0; zob_raw < 15; zob_raw++)
	{
		for (zob_column = 0; zob_column < 15; zob_column++)
		{
			for (zob_status = 0; zob_status < 15; zob_status++)
			{
				Zobrist_sheet[zob_raw][zob_column][zob_status] = rand();
				printf("%lld ", Zobrist_sheet[zob_raw][zob_column][zob_status]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	

	system("pause");
	return 0;
}

