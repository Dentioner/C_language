#include<stdio.h>

int any(char s1[], char s2[]);


int main(void)
{
	char s1[100] = { '\0' };
	char s2[100] = { '\0' };
	char ch1, ch2;
	int i;
	int position = -1;
	printf("请输入s1的内容\n");
	ch1 = getchar();
	i = 0;
	while (ch1 != '\n')
	{
		s1[i] = ch1;
		i++;

		ch1 = getchar();
	}
	
	printf("请输入s2的内容\n");
	ch2 = getchar();
	i = 0;
	while (ch2 != '\n')
	{
		s2[i] = ch2;
		i++;

		ch2 = getchar();
	}
	position = any(s1, s2);
	printf("自制的strpbrk的返回值为 position = %d\n", position);

	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;
	for (i = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i] == s2[j])
			{
				return j;
			}
		}
	}
	return -1;
}