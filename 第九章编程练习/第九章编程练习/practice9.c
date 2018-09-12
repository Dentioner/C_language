#include<stdio.h>
#include<stdbool.h>
double min(double x, double y);
bool chline(char ch, int i, int j);

int main()
{	
	
	//T1
	/*
	char crashbin;
	double x, y, output;
	printf("Please enter two numbers.\n");
	while (scanf("%lf %lf", &x, &y) != 2)
	{	
		
			
		printf("Not valid.\n");
		
		printf("Please enter two numbers.\n");
		
		while ((crashbin = getchar())!='\n')
			;

		//scanf("%s");
		
	}
	output = min(x, y);
	printf("min = %lf", output);
	*/
	//T2
	/*
	int i, j;
	int raw, column;
	char ch;
	bool no_get_it = true;
	printf("which raw and column do you prefer?\n");
	while (scanf("%d %d", &i, &j) != 2)
	{
		printf("Not valid.\n");
		printf("Please enter two numbers.\n");
		while(getchar()!='\n')
			continue;
		
	}
	getchar();
	j--;
	i--;
	raw = i;
	column = j;
	printf("Then input the text.\n");
	while (no_get_it)
	{	
		ch = getchar();
		no_get_it = chline(ch, i, j);
		if (ch == '\n')
		{
			j--;
			i = raw;
		}
			
		else
			i--;
	}
	printf("yatazze!\n");
	printf("The char is %c", ch);
	*/
	return 0;
}

double min(double x, double y)
{
	double output;
	if (x <= y)
		output = x;
	else
		output = y;
	
	return output;
}

bool chline(char ch, int i, int j)
{
	bool no_get_it = true;
	int raw = 0;
	int column = 0;
	if (raw == i && column == j)
		no_get_it = false;
	//putchar(ch);
	return no_get_it;
}