#include<stdio.h>
#include<ctype.h>
int main()
{
	char ch;
	while ((ch=getchar())!='\n')
	{
		if (isalpha(ch))
			putchar(ch + 1);
		else
			putchar(ch);

	}
	putchar(ch);
	system("pause");
	return 0;
}