#include<stdio.h>
#define PRAISE "You are an extraordinary being."
int main()
{
	char name[40];

	printf("What's your name? ");
	scanf("%s", name);/*scanֻ��ȡ����ĵ�һ���ʣ�����Kujo Jotaro ������룬��ֻ�ὫKujo��ֵ��name*/

	printf("Hello, %s. %s\n", name, PRAISE);

	system("pause");
	return 0;
}
