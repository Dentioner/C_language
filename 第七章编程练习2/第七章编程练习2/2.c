#include<stdio.h>
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25

int main()
{
	/*
	T8
	double money_origin = 0;
	double money_tax1 = 0;
	double money_tax2 = 0;
	double money_tax3 = 0;
	double money_final = 0;
	double time = 0;
	double base = 0;
	int rank = 0;
	double time_overwork = 0;
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $8.75/hr\t\t\t\t");
	printf("2) $9.33/hr\n");
	printf("3) $10.00/hr\t\t\t\t");
	printf("4) $11.20/hr\n");
	printf("5) quit\n");
	printf("*****************************************************************\n");
	
	while (scanf("%d", &rank)==0||rank<1||rank>5)
	{
		printf("Please input a useful number.\n");
		fflush(stdin);
	}
	switch (rank)
	{
	case(1):
		base = 8.75;
		break;
	case(2):
		base = 9.33;
		break;
	case(3):
		base = 10.00;
		break;
	case(4):
		base = 11.20;
		break;
	default:
		printf("\nDone\n");
		system("pause");
		exit(0);
		
	}

	printf("Please input your work time this week.\n");
	scanf("%lf", &time);
	//printf("time=%f\n",time);
	if (time > 40)
	{
		time_overwork = 1.5*(time - 40);
		time += time_overwork;
	}
	money_origin = base*time;
	money_final = money_origin;
	//printf("time=%f\n",time);
	//printf("money = %f\n", money_final);
	
	if (money_origin<=300)
	{
		money_tax1 = money_origin*TAX1;
		money_final = money_origin - money_tax1;
	}
		
	else if (money_origin>300 && money_origin<=450)
	{
		money_tax1 = 300*TAX1;
		money_tax2 = (money_origin-300)*TAX2;
		money_final = money_origin - money_tax1 - money_tax2;
	}
	else if (money_origin > 450)
	{
		money_tax1 = 300*TAX1;
		money_tax2 = 150*TAX2;
		money_tax3 = (money_origin-450)*TAX3;
		money_final = money_origin -money_tax1-money_tax2-money_tax3;
	}
	else
		;
	
	printf("Your money after tax is %f.\n", money_final);
	*/

	printf("\nDone\n");
	system("pause");
	return 0;
}


/*
void main(void)
{
    double work_hours = 0;
    double total_income = 0;
    double tax = 0;
    double  net_income = 0;

    printf("How long have you worked:");
    scanf_s("%lf", &work_hours);
	printf("time=%f\n",work_hours);
	//printf("money = %f\n", money_final);
    if (work_hours > 40)
    {
        work_hours = (work_hours - 40) * 1.5 + 40;
    }

    total_income = work_hours * 1000;
    if (total_income <= 300)
    {
        tax = total_income * RATE1;
        net_income = total_income - tax;
    }
    else if (total_income <= 450)
    {
        tax = 300 * RATE1 + (total_income - 300) * RATE2;
        net_income = total_income - tax;
    }
    else
    {
        tax = 300 * RATE1 + 150 * RATE2 + (total_income - 450) * RATE3;
        net_income = total_income - tax;
    }

    printf("total income = %lf, tax = %lf, net income = %lf\n", total_income, tax, net_income);
	system("pause");
    return;

}

*/