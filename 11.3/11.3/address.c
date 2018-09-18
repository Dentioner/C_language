#include<stdio.h>
#define MSG "I'm special."

int main()
{
	char ar[] = MSG;
	const char *pt = MSG;
	printf("Address of \"I'm special.\": %p \n", "I'm special..");
	printf("		address ar: %p\n", ar);
	printf("		address pt: %p\n", pt);
	printf("		address MSG: %p\n", MSG);
	printf("Address of \"I'm special.\": %p \n", "I'm special.");

	return 0;

}