#include<stdio.h>
int main()
{
	int n;

	printf("Please enter three integers:\n");
	scanf("%*d %*d %d", &n);/*scanf �����ʹ�����Ǻţ��ͻ�ʹ���Ǹ�%d������*/
	printf("The last integer was %d\n", n);
	
	system("pause");
	return 0;
}