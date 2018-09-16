#include<stdio.h>

void main(void)
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 200;
	step = 10;

	celsius = lower;
	printf("A table of °„C to °„F\n\n");
	printf("°„C\t°„F\n");
	while (celsius <= upper)
	{
		fahr = ((9 * celsius) / 5) + 32;
		printf("%d\t%d\n", celsius, fahr);
		celsius += step;

	}
}