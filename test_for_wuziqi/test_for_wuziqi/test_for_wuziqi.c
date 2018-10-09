#include<stdio.h>
#include<string.h>
#include<time.h>
#define bool int
#define true 1
#define false 0
#define FLOOR 3


int main()
{
	double start_time = clock();
	double end_time;
	printf("start.\n");
	system("pause");
	end_time = clock();
	printf("time=%f\n", (end_time-start_time)/CLK_TCK);

	system("pause");
	return 0;
}

