#include<stdio.h>
#include<string.h>
#define PRAISE "You are an extraordinary being."

int main()
{
	char name[40];
/*strlen����������ֵĳ��ȣ�����sizeof�����һ����40����Ϊ�����޷�֪���ַ������ĸ�λ�ÿ�ʼ���ǿ������ˡ�*/
	printf("What's your name?");
	scanf("%s", name);
	printf("Hello, %s. %s\n", name, PRAISE);
	printf("Your name of %u letters occupies %u memory cells.\n", strlen(name), sizeof name);
	printf("The phrase of praise has %u letters", strlen(PRAISE));
	printf("and occupies %u memory cells.\n", sizeof PRAISE);
/*sizeof(int) �� sizeof name����sizeof����ӵ�����ͳ���������͵�ʱ��һ��Ҫ������*/
	system("pause");
	return 0;
}
