#include<stdio.h>
#include<stdbool.h>
int main()
{
	unsigned long long num;
	unsigned long long div;
	bool isPrime;

	printf("Please enter an integer for analysis.\n");
	printf("Enter q to quit\n");
	while (scanf("%llu", &num) == 1)
	{
		for (div = 2, isPrime = true; div*div <= num; div++)
		{
			if ((num%div) == 0)
			{
				if (div*div == num)
				{
					printf("%llu的因子是%llu\n", num, div);

				}
				else
				{
					printf("%llu的因子是%llu和%llu\n", num, div, num / div);
				}
				isPrime = false;

			}
		}
		if (isPrime)
		{
			printf("%llu是素数\n", num);

		}
		printf("Please enter another integer to analyse.\n");
		printf("Enter q to quit.\n");

	}
	printf("guna.\n");
	system("pause");
	return 0;

}