#include<stdio.h>

void main(void)
{
	char repeat;
	char used_repeat = '.';
	printf("Please enter a text.\n");
	while ((repeat = getchar()) != EOF)
	{
		while (used_repeat == ' '&& repeat == ' ')
		{
			repeat = getchar();
		}
		putchar(repeat);
		used_repeat = repeat;

	}

}