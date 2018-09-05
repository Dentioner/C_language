#include<stdio.h>
#define rows 6
#define chars 10

int main()
{
	int row;
	char ch;

	for (row = 0; row<rows; row++)
	{
		for (ch = 'A'; ch < ('A' + chars); ch++)
			printf("%c", ch);
		printf("\n");
	}

	system("pause");
	return 0;
}