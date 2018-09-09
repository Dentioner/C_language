#include<stdio.h>
int main()
{
	char ch;
	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
			continue;
		printf("Step1.\n");
		if (ch == 'c')
			continue;
		else if (ch == 'b')
			break;
		else if (ch == 'h')
			goto laststep;
		printf("Step2.\n");
	laststep:printf("Step3.\n");
	}
	printf("Done");
	return 0;

}