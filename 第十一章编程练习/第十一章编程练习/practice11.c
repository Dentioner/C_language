#include<stdio.h>
#include<string.h>
#define SIZE 20

char* s_get(char*st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n'&&st[i] != '\0')
		{
			i++;
		}
		if (st[i] == '\n')
			st[i] = '\0';
		else
		{
			while (getchar() != '\n')
				continue;
			
		}
	}
	return ret_val;
}

char* my_get(char ch[], int size)
{
	for (int i = 0; i < size; i++)
	{
		ch[i] = getchar();
		
		if (ch[i] == '\0' || ch[i] == '\n' || ch[i] == '\t'||i==SIZE-1)
		{
			ch[i] = '\0';
			break;
		}
		//putchar(ch[i]);
	

	}
	return ch;
}

int main()
{
	char arr1[SIZE];
	//char *arr2;
	

	printf("Please input a string.\n");
	my_get(arr1, SIZE);
	puts(arr1);

	return 0;
}