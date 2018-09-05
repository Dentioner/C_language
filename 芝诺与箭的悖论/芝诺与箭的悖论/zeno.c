#include<stdio.h>

int main()
{
	int t_ct;
	double time, power_of_2;
	int limit;

	printf("想求这个等比数列前几项的和？:");
	scanf("%d", &limit);
	for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; t_ct++, power_of_2 *= 2.0)
	{
		time += 1.0/power_of_2;
		printf("time = %f when terms = %d.\n", time, t_ct);
	}
	system("pause");
	return 0;
}