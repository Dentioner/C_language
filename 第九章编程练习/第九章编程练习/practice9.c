#include<stdio.h>
#include<stdbool.h>
double min(double x, double y);
bool chline(char ch, int i, int j);
void pointer_change(double *x, double *y, double*z);
int where_is_it(char letter);
double power(double n, int p, double consequence);
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
	//T6
	/*
	double x, y, z;
	printf("Please input 3 numbers.\n");
	scanf("%lf %lf %lf", &x, &y, &z);
	printf("Now the 3 numbers are x=%lf, y=%lf, z=%lf\n", x, y, z);
	pointer_change(&x, &y, &z);
	printf("Now the 3 numbers become x=%lf, y=%lf, z=%lf\n", x, y, z);
*/
	//T7
	/*
	char letter;
	int loc;
	printf("Please input a text.\n");
	while ((letter = getchar()) != EOF)
	{
		fflush(stdin);
		loc = where_is_it(letter);
		printf("字母在第%d位\n", loc);
	}
	*/

	//T8&T9
/*
	double n;
	int p;
	
	char quit;
	printf("按q退出，其它任意键开始\n");
	while ((quit = getchar()) != 'q')
	{
		while (getchar() != '\n')
			continue;
		double consequence=1.0;
		printf("请输入底数和指数\n");
		while ((scanf("%lf %d", &n, &p))!=2)
		{
			printf("输入无效，请再输入一次\n");
			while (getchar() != '\n')
				continue;
		}

		consequence = power(n, p, consequence);
		printf("结果是%lf\n", consequence);

		printf("按q退出，其它任意键继续\n");
		while (getchar() != '\n')
			continue;
		
	}
	
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
/*
void pointer_change(double *x, double *y, double*z)
{
	double tx, ty, tz;
	double s, m, l;
	tx = *x;
	ty = *y;
	tz = *z;
	
	if (tx > ty)
	{
		
		if (ty > tz)
		{
			s = tz;
			l = tx;
			m = ty;
		}
		else
		{
			if (tx > tz)
			{
				l = tx;
				m = tz;
				s = ty;
			}
			else
			{
				l = tz;
				m = tx;
				s = ty;
			}
		}
	}
	else
	{
		if (ty < tz)
		{
			m = ty;
			l = tz;
			s = tx;
		}
		else
		{
			if (tx > tz)
			{
				s = tz;
				m = tx;
				l = ty;
			}
			else
			{
				l = ty;
				m = tz;
				s = tx;
			}
			
		}
	}
	*x = s;
	*y = m;
	*z = l;
	return;
}*/
//以上是我自己的排序
//以下是冒泡排序法
void pointer_change(double *x, double *y, double*z)
{
	double tx, ty, tz;
	double temp = 0.0;
	tx = *x;
	ty = *y;
	tz = *z;
	if (tx > ty)
	{
		temp = tx;
		tx = ty;
		ty = temp;
	}
	if (tx > tz)
	{
		temp = tx;
		tx = tz;
		tz = temp;
	}
	if (ty > tz)
	{
		temp = ty;
		ty = tz;
		tz = temp;
	}
	*x = tx;
	*y = ty;
	*z = tz;

}

int where_is_it(char letter)
{
	char const_letter = 'a';
	char const_Letter = 'A';
	int location = 1;
	while (letter != const_letter && letter != const_Letter)
	{
		if (location > 26)
		{
			location = -1;
			break;
		}
		location++;
		const_Letter++;
		const_letter++;
	}
	

	return location;
}
/*非递归
double power(double n, int p)
{
	int index;
	double consequence =1;
	
	if (p == 0)
	{
		consequence = 1;
	}
	else
	{
		for (index = 0; index < p; index++)
		{
			consequence *= n;
		}
		
	}
	
	
}
*/
//下面是递归
double power(double n, int p, double consequence)
{
	consequence *= n;
	if (p>1)
	{
		consequence = power(n, p - 1, consequence);
	}
	return consequence;
}
