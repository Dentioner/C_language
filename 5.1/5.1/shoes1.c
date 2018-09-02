#include<stdio.h>
#define ADJUST 7.31
int main()
{
	const double SCALE = 0.333;
	double shoe, foot;

	shoe = 9.0;
	foot = SCALE*shoe + ADJUST;
	printf("Shoe size (men's)\tfoot length\n");
	printf("%10.1f\t%15.2f inches\n", shoe, foot);
	
	system("pause");
	return 0;
}