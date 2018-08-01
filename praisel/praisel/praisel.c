#include<stdio.h>
#define PRAISE "You are an extraordinary being."
int main()
{
	char name[40];

	printf("What's your name? ");
	scanf("%s", name);/*scan只读取词组的第一个词，例如Kujo Jotaro 这个输入，它只会将Kujo赋值给name*/

	printf("Hello, %s. %s\n", name, PRAISE);

	system("pause");
	return 0;
}
