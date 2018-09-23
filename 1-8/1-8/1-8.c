#include<stdio.h>

void main(void)
{
	int blank = 0;
	int tab = 0;
	int enter = 0;
	char ch;
	printf("Please enter a part of text.\n");
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
			enter++;
		if (ch == '\t')
			tab++;
		if (ch == ' ')
			blank++;

	}
	printf("Totally,\nenter:%d\t tab:%d\t blank:%d\t", enter, tab, blank);
}