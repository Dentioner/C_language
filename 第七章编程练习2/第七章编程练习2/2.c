#include<stdio.h>
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25
int main()
{
	float money_origin = 0;
	float money_tax1 = 0;
	float money_tax2 = 0;
	float money_tax3 = 0;
	float money_final = 0;
	float time = 0;
	const float base = 10.00;
	float time_overwork = 0;
	printf("Please input your work time this week.\n");
	scanf("%f", &time);
	if (time > 40)
	{
		time_overwork = 1.5*(time - 40);

	}
	money_origin = 10.00*time;
	money_final = money_origin;
	//这下面重新写一下，计算税后收入有点问题
	if (money_origin>300)
	{
		money_tax1 = 300*TAX1;
		money_final = money_origin - money_tax1;
		if (money_final>150)
		{
			money_tax2 = 150
		}
	}
	
	printf("\nDone\n");
	system("pause");
	return 0;
}