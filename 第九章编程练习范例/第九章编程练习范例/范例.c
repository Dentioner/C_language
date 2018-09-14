#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
/*
void chline(char *ch, int i, int j)
{
	int m = 0;
	int n = 0;
	int tmp = 0;
	while ((*(ch + tmp)) != '\0')
	{

		if (m == i - 1)
		{
			break;
		}
		if ('\n' == (*(ch + tmp)))
		{
			m++;
		}
		tmp++;
	}

	for (n = 0; n < j; n++)
	{
		if (n == j - 1)
		{
			putchar(ch[tmp]);
		}
		tmp++;
	}
}
void main(void)
{
	int i = 0;
	int j = 0;
	char ch = 0;
	char *words = "hello world!\nThis is the bulteaful world!\nLearn to program in c language!\nc language is a nice language!";

	printf("Please enter the row:");
	scanf_s("%d", &i);
	getchar();

	printf("Please enter the column:");
	scanf_s("%d", &j);
	getchar();

	printf("The character of %d row %d column is ", i, j);
	chline(words, i, j);

	printf("\n");

	return;
}
*/
void rank_three_double(double *number1, double *number2, double *number3)
{
	double tmp = 0.0;
	if (*number1 > *number2)
	{
		tmp = *number1;
		*number1 = *number2;
		*number2 = tmp;
	}
	if (*number1 > *number3)
	{
		tmp = *number1;
		*number1 = *number3;
		*number3 = tmp;
	}
	if (*number2 > *number3)
	{
		tmp = *number2;
		*number2 = *number3;
		*number3 = tmp;
	}
	return;
}
void p9_6(void)
{
	double number1 = 0.0;
	double number2 = 0.0;
	double number3 = 0.0;

	printf("Enter the first double number:");
	scanf_s("%lf", &number1);
	getchar();

	printf("Enter the second double number:");
	scanf_s("%lf", &number2);
	getchar();

	printf("Enter the third double number:");
	scanf_s("%lf", &number3);
	getchar();

	printf("Before rank, the three double number are: %lf, %lf and %lf\n", number1, number2, number3);
	rank_three_double(&number1, &number2, &number3);
	printf("After rank, the three double number are: %lf, %lf and %lf\n", number1, number2, number3);

	return;
}
