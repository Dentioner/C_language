#include<stdio.h>
#include<stdbool.h>
void temperature_switch(int mode_choice);

int main(void)
{
	int mode_choice = 0;
	int mode_choice_index = 0;
	bool invalid_mode = true;
	printf("Please choose a mode.\n");
	printf("1. °„F to °„C\t 2. °„C to °„F\n");
	while (invalid_mode)
	{
		mode_choice_index = scanf("%d", &mode_choice);
		while (getchar() != '\n')
			continue;
		if (mode_choice_index != 1)
		{
			printf("Invalid choice.Please enter a number again.\n");

			continue;
		}
		if ((mode_choice != 1) && (mode_choice != 2))
		{
			printf("Invalid choice.Please enter a number again.\n");

			continue;
		}

		invalid_mode = false;
	}
	
	temperature_switch(mode_choice);
	return 0;
}

void temperature_switch(int mode_choice)
{
	int fahr, celsius;
	int lower, upper, step;
	lower = 0;
	

	
	system("cls");
	if (mode_choice == 1)
	{
		fahr = lower;
		step = 20;
		upper = 300;
		printf("A table of °„F to °„C\n\n");
		printf("°„F\t°„C\n");
		while (fahr <= upper)
		{
			celsius = 5 * (fahr - 32) / 9;
			printf("%d\t%d\n", fahr, celsius);
			fahr += step;
		}
	}
	else
	{
		celsius = lower;
		step = 10;
		upper = 200;
		printf("A table of °„C to °„F\n\n");
		printf("°„C\t°„F\n");
		while (celsius <= upper)
		{
			fahr = ((9 * celsius) / 5) + 32;
			printf("%d\t%d\n", celsius, fahr);
			celsius += step;

		}
	}

	return;
}