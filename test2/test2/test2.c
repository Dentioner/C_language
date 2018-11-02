#include<stdio.h>
int a;
a = 0;
int main()
{

	
		char* str1 = "HaLLo, world";
		char* str2 = "Welcome you";
		char* strp = strpbrk(str1, str2);
		if (strp != NULL)
			printf("%s\n", strp);
		return 0;

}