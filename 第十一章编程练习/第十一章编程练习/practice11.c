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

char* question10(char arr[])
{
	int i = 0;
	char ch;
	ch = getchar();
	
	while (ch != '\n')
	{
		if (ch != ' ')
		{
			arr[i] = ch;
			i++;
		}
			
		ch = getchar();
		
		//i++;
	}
	arr[i] = '\0';

	return arr;
}

void statistic(char text[], int para[])
{
	int i = 0;
	char ch;
	ch = getchar();
	while (ch != EOF)
	{
		if ((ch >= 33 && ch <= 47)
			|| (ch >= 58 && ch <= 64)
			|| (ch >= 91 && ch <= 96)
			|| (ch >= 123 && ch <= 126))
		{
			para[3]++;
		}
		else if ((ch >= 65 && ch <= 90))
		{
			para[1]++;
		}
		else if ((ch >= 97 && ch <= 122))
		{
			para[2]++;
		}
		else if ((ch >= 48 && ch <= 57))
		{
			para[4]++;
		}
		else if (ch == 32)
		{
			para[0]++;
		}
		else
			;
		text[i] = ch;
		i++;

		ch = getchar();
	}
	text[i] = '\0';

	return;
}

/*void reverse(char sentence[])
{
	int len;
	int column;
	int re_pointer[SIZE];
	int i_re_ptr = 0;
	char* re;
	len = strlen(sentence);
	for (int i = 0; i < len; i++)
	{
		if (sentence[i] == ' ')
		{
			re_pointer[i_re_ptr] = i;
			i_re_ptr++;
			sentence[i] = '\0';
		}
	}

	re_pointer[i_re_ptr] = '\0';
	for (int i = i_re_ptr-1; i >= 0; i--)
	{
		int index = re_pointer[i];
		re = sentence + index;
		fputs(re, stdout); 
	}

//	char r_sentence[SIZE];
	
	return;
}

*/


void cut(char arr[], char ch)
{

	char **output;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == ch)
		{

		}
	}
}

int main()
{
	char arr1[SIZE];
	//char *arr2;
	int para[5] = { 0,0,0,0,0 };
	

	printf("Please input a string.\n");
	s_get(arr1, SIZE);

	//statistic(arr1, para);
	reverse(arr1);

	//puts(arr1);
	//printf("单词数\t大写数\t小写数\t标点数\t数字数\n");
	/*for (int j = 0; j < 5; j++)
	{
		printf("%d\t", para[j]);
	}
	*/
	return 0;
}