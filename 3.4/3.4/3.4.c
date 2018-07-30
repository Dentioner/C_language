#include<stdio.h>
int main()
{
	int i = 2147483647;
	unsigned int j = 4294967295;/*unsigned int 是没有负号的int类型*/

	printf("%d %d %d\n", i, i+1, i+2);
	printf("%u %u %u\n", j, j+1, j+2);

	system("pause");
	return 0;
}
/*超出范围之后，int和unsigned int就会从头开始计数。前者为-2147483648，后者为0*/