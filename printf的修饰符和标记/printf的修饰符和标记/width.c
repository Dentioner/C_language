#include<stdio.h>
/*#define PAGES 959*/
int main()
{/*
	int PAGES;
	printf("Please input a number.\n");
	scanf("%d", &PAGES);
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);
*/
	/*const double RENT = 3852.99;*/
	double RENT;/*这个double换成float就正常了*/
	printf("Please input a number.\n");
	scanf("%f", &RENT);
	printf("*%f*\n", RENT);
	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3E*\n", RENT);
	printf("*%+4.2f*\n", RENT);
	printf("*%010.2f*\n", RENT);

	
	system("pause");
	return 0;
}
