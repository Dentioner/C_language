#include<stdio.h>
#include<math.h>
#include <stdafx.h>
int main()
{
	int i = -1;
	char input[256];

	printf("Please input the string:");

	do
	{
		i++;
		scanf_s("%c", &input[i]);
	} while (input[i] != '\n');

	for (size_t j = i; j > 0; j--)
	{
		printf("%c", input[j - 1]);
	}
	printf("\n");

	system("pause");
	return 0;
}
