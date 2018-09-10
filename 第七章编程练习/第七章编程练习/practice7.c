#include<stdio.h>
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25
int main()
{
/*
	T1
	char ch;
	int kongge = 0;
	int huanhang = 0;
	int all = 0;

	printf("输入一串字符.输入'#'时退出.\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == ' ')
			kongge++;
		else if (ch == '\n')
			huanhang++;
		else
			all++;

	}
	printf("完了.\n");
	printf("共计%d个空格，%d个换行，%d个其他字符", kongge, huanhang, all);
	
	T2
	char ch;
	int times = 0;
	printf("输入一串字符.输入'#'时退出.\n");
	while ((ch = getchar()) != '#')
	{
		printf("%c-%d\t", ch, ch);


		times++;
		
		if ((times%8)==0 && (times != 0))
			printf("\n");
	}
	printf("\nguna.\n");
	
	
	*/
	/*T3
	int ch;
	int ou = 0;
	int ji = 0;
	int sum_ou = 0;
	int sum_ji = 0;
	printf("Please input a number.\n");
	printf("Enter 0 to quit.\n");
	while ((scanf("%d", &ch)) != 0 && ch != 0)
	{
		//printf("fuck you.\n");
		//printf("%d\n", ch);
		
		if ((ch % 2) == 0)
		{
			ou++;
			sum_ou += ch;

		}
		else
		{
			ji++;
			sum_ji += ch;
		}

	}
	printf("总共输入了%d个偶数，%d个奇数.\n", ou, ji);
	if (ou != 0 && ji != 0)
	{

		printf("偶数平均为%.2f，奇数平均为%.2f.\n", ((float)sum_ou / (float)ou), ((float)sum_ji / (float)ji));
	}
	else if (ou == 0)
		printf("奇数平均为%.2f.\n",  ((float)sum_ji / (float)ji));
	else
		printf("偶数平均为%.2f.\n", ((float)sum_ou / (float)ou));
		
	T4
	char ch;
	int change = 0;
	printf("***text changer***\n");
	printf("Please input the text.\nEnter # to exit.\n");

	while ((ch = getchar()) != 0)
	{
		if (ch == '#')
			break;
		else if (ch == '.')
		{
			ch = '!';
			change++;
		}
		else if (ch == '!')
		{
			putchar(ch);
			change++;
		}
			
		else
			;
		putchar(ch);

	}
	printf("\nIn total, %d %s happened.", change, ((change == 1) ||(change ==0)) ? "change" : "changes");
	
T5
	char ch;
	int changes = 0;
	printf("***text changer***\n");
	printf("Please input the text.\nEnter # to exit.\n");
	while ((ch = getchar()) != 0)
	{
		if (ch == '#')
			break;
		//printf("\nPlease input the text.\nEnter # to exit.\n");
		switch (ch)
		{
		
		case '.':
			ch = '!';
			putchar(ch);
			changes++;
			break;
		case'!':
			putchar(ch);
			putchar(ch);
			changes++;
			break;
		default:
			putchar(ch);
			break;
		}
	}
	printf("\nIn total, %d %s happened.", changes, ((changes == 1) || (changes == 0)) ? "change" : "changes");

T6
	char ch;
	char re_ch;
	int change = 0;
	printf("Please input the text.\nEnter # to exit.\n");
	while ((ch = getchar()) != 0)
	{
		if (ch == '#')
			break;
		//else if (ch == 'e')
		//{
			//re_ch = 'e';
			//continue;

		//}
		else if (ch == 'i')
		{
			if (re_ch == 'e')
				change++;

			//continue;

		}
		else
			;
		re_ch = ch;
		putchar(ch);

	}
	printf("\nIn total, %d %s happened.", change, ((change == 1) || (change == 0)) ? "change" : "changes");
*/
	float money = 0;
	float time = 0;
	const float base = 10.00;
	float time_overwork = 0;
	printf("Please input your work time this week.\n");
	scanf("%f", &time);
	if (time > 40)
	{
		time_overwork = 1.5*(time - 40);

	}
	printf("\nDone\n");
	system("pause");
	return 0;
}