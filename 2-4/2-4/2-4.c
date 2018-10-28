#include<stdio.h>


void squeeze(char s1[], char s2[]);

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

	printf("s1:%s\n", s1);
	printf("s2:%s\n", s2);
	squeeze(s1, s2);
	printf("s1:%s\n", s1);

	return 0;


}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	for (k = 0; s2[k] != '\0'; k++)
	{
		for (i = j = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] != s2[k])
			{
				s1[j++] = s1[i];
			}
		}
	
		s1[j] = '\0';
	}


}