#include<stdio.h>

double harmonic_mean(double x, double y);
void pointer_change(double *x, double*y, double*z);
int main()
{
//T4
/*
	double x;
	double y;
	double avg;
	printf("Please input two numbers.\n");
	scanf("%lf %lf", &x, &y);
	avg = harmonic_mean(x, y);
	printf("The average is %lf.\n", avg);

	*/
	double x, y, z;
	printf("Please input 3 numbers.\n");
	scanf("%lf %lf %lf", &x, &y, &z);
	pointer_change(&x, &y, &z);
	printf("Now the 3 numbers become x=%lf, y=%lf, z=%lf", x, y, z);
	

	system("pause");
	return 0;
}

double harmonic_mean(double x, double y)
{
	double temp_x, temp_y;
	double temp_avg;
	double avg;
	temp_x = 1/x;
	temp_y = 1/y;
	temp_avg = (temp_x + temp_y)/2;
	avg = 1/temp_avg;
	return avg;
}



void pointer_change (double *x, double *y, double*z)
{
	double small, medium, big;
	if (x<=y)
	{
		if(x<=z)
		{
			small = x;
		}
		else
		{
			small = z;
		}

	else
	{
		if ()