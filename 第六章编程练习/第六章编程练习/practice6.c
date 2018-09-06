#include<stdio.h>
int main()
{/*T1
	char alphabet[26];
	int i;
	char alpha = 'a';
	for (i = 0; i < 26; i++)
	{
		alphabet[i] = alpha;
		alpha++;
		printf("%c", alphabet[i]);

	}


	T2
	int i,j;
	for (i = 1; i < 6; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("$");
		}
		printf("\n");
	}
	
	T3
	char i;
	int j,k;
	for (j = 1; j < 7; j++)
	{
		for (i = 'F', k=0; k < j; k++)
		{
			printf("%c", i-k);
			
		}
		printf("\n");
	}
	
T4
	int i,j;
	char ch = 'A';
	for (i = 1; i < 7; i++)
	{
		for (j = 0; j < i; j++)
		{
			
			printf("%c", ch);
			ch ++;
		}
		printf("\n");
	}

T5
	char input;
	char initial = 'A';
	int i;//i是第几行
	int hang;//这个是算总共的行数
	int j;//每一行的空格数
	int k;//每一行的字母数
	
	printf("please input a character.\n");
	scanf("%c", &input);

	hang = (int)input - (int)initial + 2;
	
	for (i = 1; i < hang; i++)
	{
		for (j = 0; j < hang - 1 -i; j++)
		{
			printf(" ");
		}
		for (k = 0; k < i; k++)
		{
			printf("%c", initial + k);
		}
		for (k = i-1; k > 0; k--)
		{
			printf("%c", initial + k -1);
		}



		printf("\n");
	}
*/

	

	system("pause");
	return 0;
}
