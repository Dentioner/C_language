#include<stdio.h>
#define MSG "My waifu is Battleship-Symbiotic Hime."
#define MAXLENGTH 81

int main()
{
	char words[MAXLENGTH] = "I am a string in an array.";
	const char*pt1 = "Something is pointing at me.";
	puts("Here are some strings:");
	puts(MSG);
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);

	printf("%s, %p, %c\n", "We", "are", *"space farers");

	return 0;

}