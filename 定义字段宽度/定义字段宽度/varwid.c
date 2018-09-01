#include<stdio.h>
int main()
{
	unsigned width, precision;
	int number = 256;
	double weight = 242.5;

	printf("Enter a field width:\n");
	scanf("%d", &width);
	printf("The number is △%*d△\n", width, number);
	printf("Now enter a width and a precision:\n");
	scanf("%d %d", &width, &precision);
	printf("Weight = ◇%*.*f◇\n", width, precision, weight);/*注意，两个星号对应了两个变量，就是width和precision*/
	printf("Done!\n");

	system("pause");
	return 0;
}