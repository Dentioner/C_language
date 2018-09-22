#include<stdio.h>
#include<string.h>

int main()
{
	char column_c;//字母形式的纵坐标
	int raw, column;
	//char black[2] = "○";
	//char white[2] = "●";
	//下面是用户输入的坐标，还需处理
	//printf("请选择下一步，先输入一个行数，例如：2\n");
	while (scanf("%d", &raw)!=1 && (1<= raw && raw<=15))
	{
		printf("无效输入，请重试");
		while (getchar() != '\n')
			continue;
	}

	while (getchar() != '\n')
			continue;

	//printf("再输入一个列数，例如：B\n");
	column_c = getchar();
	while (getchar() != '\n')
		continue;
	while (column_c<'A' || (column_c > 'Z'&&column_c < 'a') || column_c>'z')
	{
		printf("无效输入，请重试");
		
		column_c = getchar();
		while (getchar() != '\n')
			continue;

	}

	return 0;

}