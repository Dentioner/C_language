#include<stdio.h>
#define PAGES 336
#define WORDS 65618
int main()
{
	short num = PAGES;
	short mnum = -PAGES;

	printf("num as short and unsigned short:  %hd %hu\n", num, num);
	printf("-num as short and unsigned short: %hd %hu\n", mnum, mnum);
	printf("num as int and char: %d %c\n", num, num);/*这个相当于336mod256=80，因此%c输出的是80对应的字符P*/
	printf("WORDS as int, short, and char: %d %hd %c\n", WORDS, WORDS, WORDS);
	
	getchar();
	return 0;
}
