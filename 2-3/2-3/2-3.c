#include<stdio.h>
#include<string.h>
#define CHAR_SIZE 100

unsigned int htoi(char hex_number[]);


int main(void)
{
	char hex_number[CHAR_SIZE] = { '\0' };
	char ch;
	int i = 0;
	unsigned int int_number = 0;
	printf("请输入一个16进制的数字\n");
	ch = getchar();
	while (ch != '\n')
	{
		hex_number[i] = ch;
		i++;

		ch = getchar();
	}

	int_number = htoi(hex_number);
	printf("数字换算成十进制是%u\n", int_number);

	return 0;
}

unsigned int htoi(char hex_number[])
{
	unsigned int number = 0;
	unsigned int index;
	if (hex_number[0] == '0' && ((hex_number[1] == 'x') || (hex_number[1] == 'X')))
	{
		
		for (index = 2; index <= strlen(hex_number) - 1; index++)
		{
			if ((hex_number[index] >= '0') && (hex_number[index] <= '9'))
			{
				number = number * 16 + (hex_number[index] - '0');
			}
			else if ((hex_number[index] >= 'A') && (hex_number[index] <= 'F'))
			{
				number = number * 16 + (hex_number[index] - 'A' + 10);
			}
			else if ((hex_number[index] >= 'a') && (hex_number[index] <= 'f'))
			{
				number = number * 16 + (hex_number[index] - 'a' + 10);
			}
			else
			{
				printf("这个数组不是纯数字\n");
				exit(0);
			}



			
		}

		return number;
	}
	else 
	{
		for (index = 0; index <= strlen(hex_number) - 1; index++)
		{
			if ((hex_number[index] >= '0') && (hex_number[index] <= '9'))
			{
				number = number * 16 + (hex_number[index] - '0');
			}
			else if ((hex_number[index] >= 'A') && (hex_number[index] <= 'F'))
			{
				number = number * 16 + (hex_number[index] - 'A' + 10);
			}
			else if ((hex_number[index] >= 'a') && (hex_number[index] <= 'f'))
			{
				number = number * 16 + (hex_number[index] - 'a' + 10);
			}
			else
			{
				printf("这个数组不是纯数字\n");
				exit(0);
			}




		}

		return number;
	}
	
}

