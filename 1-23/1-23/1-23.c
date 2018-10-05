#include<stdio.h>

void delete_notation(void);
int main(void)
{
	delete_notation();
	return 0;
}

void delete_notation(void)
{
	int ch;
	int state = 0;
	while ((ch = getchar()) != EOF)
	{
		if (state == 0 && ch == '/')
		{
			state = 1;
		}
		else if (state == 0 && ch == '\"')
		{
			state = 7;
		}
		else if (state == 0 && ch == '\'')
		{
			state = 5;
		}
		else if(state == 1 && ch !='/' && ch!='*')
		{
			state = 0;
			putchar('/');
		}
		else if (state == 1 && ch == '/')
		{
			state = 4;//state4就是单行注释状态
		}
		else if (state == 1 && ch == '*')
		{
			state = 2;//开始多行注释
		}
		else if (state == 2 && ch == '*')
		{
			state = 3;
		}
		else if (state == 2 && ch != '*')
		{
			state = 2;
		}
		else if (state == 3 && ch == '*')
		{
			state = 3;
		}
		else if (state == 3 && ch == '/')
		{
			state = 0;
		}
		else if (state == 3 && ch != '/'&& ch != '*')
		{
			state = 2;
		}
		else if (state == 4 && ch == '\n')//结束单行注释
		{
			state = 0;
		}
		else if (state == 4 && ch == '\\')
		{
			state = 9;
		}
		else if (state == 5 && ch == '\\')
		{
			state = 6;
		}
		else if (state == 5 && ch == '\'')
		{
			state = 0;
		}
		else if (state == 6)
		{
			state = 5;
		}
		else if (state == 7 && ch == '\\')
		{
			state = 8;
		}
		else if (state == 7 && ch == '\"')
		{
			state = 0;
		}
		else if (state == 8)
		{
			state = 7;
		}
		else if (state == 9 && ch == '\\')
		{
			state = 9;
		}
		else if (state == 9 && ch != '\\')
		{
			state = 4;
		}
	
		if ((state == 0 && ch != '/') || (state == 5) || (state == 6) || (state == 7) || (state == 8))
		{
			putchar(ch);
		}
	
	}
}