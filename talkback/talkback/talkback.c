#include<stdio.h>
#include<string.h>
#define DENSITY 62.4
int main()
{
	float weight, volume;
	int size, letters;
	char name[40];/*字符串的最后一位必须留空，因此name的长度不大于39个字符*/
	/*因此'A'与"A"是不一样的，前者是一个基本字符，后者是一个派生类型实际上由两个基本字符组成，
	是'A'与'/0'，而不仅仅是'A'*/

	printf("Hi, What's your first name?\n");
	scanf("%s", name);
	printf("%s, what's your weight in pounds?\n", name);
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight/DENSITY;
	printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
	printf("Also your first name has %d letters,\n", letters);
	printf("and we have %d bytes to store it.\n", size);

	system("pause");
	return 0;
}
