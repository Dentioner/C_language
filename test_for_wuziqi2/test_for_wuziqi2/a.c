#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void main()
{

/*


	int zob_raw, zob_column, zob_status;
	long long int a, b, c, d;
	srand(time(NULL));
	long long int Zobrist_sheet[15][15][3] = { 0 };
	for (int zob_raw = 0; zob_raw < 15; zob_raw++)
	{
		for (int zob_column = 0; zob_column < 15; zob_column++)
		{
			for (int zob_status = 0; zob_status < 3; zob_status++)
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
	printf("d = %d\n", Zobrist_sheet[3][2][1]);
	d = Zobrist_sheet[3][2][1];
	d = d^12356465131315615;
	printf("d = %d\n", d);
	d = d^12356465131315615;
	printf("d = %d\n", d);

	system("pause");
	*/

/*
	long long int key[15][15][2] = { 0 };
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
				printf("%d,%d  ", key[i][j][0], key[i][j][1]);
		}
		printf("\n");
	}
	

	int step;
	scanf("%d", &step);
	printf("%d", step % 2);
*/
	int i = 0;
	while (1)
	{
		i++;
		if (i == 10)
		{
			printf("%d", i);
			exit(0);
		}
	}
}