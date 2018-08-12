#include<stdio.h>
#define BLURB "Authentic imitation!"
int main()
{
	printf("[%2s]\n", BLURB);
	printf("[%24s]\n", BLURB);
	printf("[%24.5s]\n", BLURB);
	printf("[%-24.5s]\n", BLURB);

	getchar();
	return 0;
}
/*%24.5s的意思是，打印的字段有24个单位长度，但是只打印5个字符*/