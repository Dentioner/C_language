#include<stdio.h>
void p1(void);
void p3(void);
void p4_1(void);
void p4_2(void);
void p7(void);
void p1(void)
{
	printf("Gustav Mahler\n");
	printf("Gustav\nMahler\n");
	printf("Gustav ");
	printf("Mahler\n");
}

void p3(void)
{
	int age_years, age_days;
	age_years = 20;
	age_days = age_years*365;
	printf("My age is %d, it is equal to %d days.\n", age_years, age_days);
}

void p4_1(void)
{
	int i;
	i = 0;
	while (i < 3){
		printf("For he's a jolly good fellow!\n");
		i += 1;
	}
}
void p4_2(void)
{
	printf("Which no body can deny!\n");
}
void p7(void)
{
	int i,j;
	i = 0;
	
	while (i<3){
		j = i;
		while(j<3){
			printf("smile");
			j += 1;
		}
		printf("\n");
		i += 1;
	}
}


main()
{
	p1();
	p3();
	p4_1();
	p4_2();
	p7();
	system("pause");
}
