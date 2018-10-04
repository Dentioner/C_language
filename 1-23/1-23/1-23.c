#include<stdio.h>




int main(void)
{
	int ch;
	int re_ch = 'a';
	while ((ch = getchar()) != EOF)
	{
		if ((ch == '/')&&(re_ch !='/'))
		{
			re_ch = ch;
			
		}

		/*
		else if ((re_ch == '/') && (ch != '/'))
		{
			putchar(re_ch);
			putchar(ch);
		}
		*/
		else if ((re_ch == '/') && (ch != '*') && (ch != '/'))
		{
			putchar(re_ch);
			putchar(ch);
		}
		else if ((ch == '*') && (re_ch != '/'))
		{
			putchar(ch);

		}
		else if ((ch == '/') && (re_ch == '/'))
		{
			while ((ch = getchar()) != EOF)
			{
				if (ch == '\n')
				{
					putchar(ch);
					re_ch = 'a';
					break;
				}
			}

		}
		else if ((re_ch == '/') && (ch == '*'))
		{
			while ((ch = getchar()) != EOF)
			{
				if (ch == '*')
				{
					re_ch = ch;
				}
				else if ((ch == '/') && (re_ch == '*'))
				{
					while ((getchar() != '\n'))
						continue;
					break;
				}
	
					
			}
		}
		else
		{
			putchar(ch);
		}
		
		if (ch == EOF)
		{
			break;
		}
	}
		
	return 0;


}