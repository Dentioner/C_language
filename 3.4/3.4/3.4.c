#include<stdio.h>
int main()
{
	int i = 2147483647;
	unsigned int j = 4294967295;/*unsigned int ��û�и��ŵ�int����*/

	printf("%d %d %d\n", i, i+1, i+2);
	printf("%u %u %u\n", j, j+1, j+2);

	system("pause");
	return 0;
}
/*������Χ֮��int��unsigned int�ͻ��ͷ��ʼ������ǰ��Ϊ-2147483648������Ϊ0*/