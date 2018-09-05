#include<stdio.h>
#define htomin 60

void Temperatures(double);
int main()
{
	/*T1
	float minute;
	int hour;
	float left;
	printf("please input a time.\n");
	scanf("%f", &minute);
	while (minute>0)
	{
		hour = (int)minute/htomin;
		left = minute - (hour*htomin);
		printf("the time is equal to %2d:%2.0f.\n", hour, left);
		printf("please input a time.\n");
		printf("If you do not want to continue, input 0.\n");
		scanf("%f", &minute);
	}
	printf("done.\n");
T2
	int input = 0;
	int i = 0;
	printf("please input a number.\n");
	scanf("%d", &input);
	while (i++<11)
	{
		printf("%d\t", input);
		input++;
	}
	
	T7
	double input = 0.0;
	double answer = 0;
	printf("please input a number.\n");
	scanf("%lf", &input);
	printf("%f\n", input);
	answer = input*input*input;
	printf("%f的立方为%f", input, answer);
	
	t8
	int mod = 0;
	int target = 0;
	int conse = 0;
	printf("输入一个模数\n");
	scanf("%d", &mod);
	printf("输入被除数\n");
	scanf("%d", &target);
	
	conse = target%mod;
	printf("%d mod %d = %d\n", target, mod, conse);
	*/
	double temp = 0;
	int test = 0;
	printf("输入一个华氏温度.\n");
	test = scanf("%lf", &temp);
	while(test == 1)
	{	
		getchar();
		Temperatures(temp);
		printf("输入一个华氏温度.\n");
		test = scanf("%lf", &temp);
	}
	system("pause");
	return 0;
}

void Temperatures(const double a)
{
	
	double c = 0;
	double K = 0;
	printf("%lf\n", a);
	c = 5.0/9.0*(a - 32.0);
	K = c + 237.16;

	printf("相当于%.2lf℃，%.2lfK.\n", c, K);
}