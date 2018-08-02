#include<stdio.h>
#include<string.h>
#define PRAISE "You are an extraordinary being."

int main()
{
	char name[40];
/*strlen输出的是名字的长度，但是sizeof输出的一定是40，因为后者无法知道字符串在哪个位置开始就是空数据了。*/
	printf("What's your name?");
	scanf("%s", name);
	printf("Hello, %s. %s\n", name, PRAISE);
	printf("Your name of %u letters occupies %u memory cells.\n", strlen(name), sizeof name);
	printf("The phrase of praise has %u letters", strlen(PRAISE));
	printf("and occupies %u memory cells.\n", sizeof PRAISE);
/*sizeof(int) 与 sizeof name，当sizeof后面接的是笼统的数据类型的时候，一定要有括号*/
	system("pause");
	return 0;
}
