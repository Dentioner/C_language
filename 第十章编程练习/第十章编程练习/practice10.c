#include<stdio.h>
void copy_arr(double[], double[], int n);
void copy_ptr(double*, double*, int n);
void copy_ptrs(double[], double[], double *);
void reversal(double[], double[], int n);
double average(double[], int n);
double max(double, double);
int main()
{

	//T2
	/*
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];
	double target3[5];
	int i;
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);

	for (i = 0; i < 5; i++)
	{
		printf("%lf ", target1[i]);
	}
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("%lf ", target2[i]);
	}
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("%lf ", target3[i]);
	}
	printf("\n");
*/

	//T6
	/*
	int i;
	double arr[] = { 1,2,3,4,5,6 };
	double arr2[6];
	reversal(arr, arr2, 6);
	for (i = 0; i < 6; i++)
	{
		printf("%lf ", arr[i]);
	}
	printf("\n");

	for (i = 0; i < 6; i++)
	{
		printf("%lf ", arr2[i]);
	}
	printf("\n");
*/

	double arr[3][5];
	double avg1, avg2, avg3;
	double maximum = 0;
	printf("Please enter 5 double.1\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%lf", &arr[0][i]);
	}

	printf("Please enter 5 double.2\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%lf", &arr[1][i]);
	}
	printf("Please enter 5 double.3\n");

	for (int i = 0; i < 5; i++)
	{
		scanf("%lf", &arr[2][i]);
	}

	avg1 = average(arr[0], 5);
	avg2 = average(arr[1], 5);
	avg3 = average(arr[2], 5);
	printf("avg1=%lf, avg2=%lf, avg3=%lf\n", avg1, avg2, avg3);
	
	maximum = arr[0][0];
	for (int c = 0; c < 3; c++)
	{
		for (int r = 0; r < 5; r++)
		{
			maximum = max(maximum, arr[c][r]);
		}
		
	}

	printf("max = %lf\n", maximum);

	return 0;
}

void copy_arr(double target[], double source[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		target[i] = source[i];
	}
}

void copy_ptr(double*target, double*source, int n)
{
	int i = 0;
	while (i < 5)
	{
		*target = *source;
		target++;
		source++;
		i++;
	}
}

void copy_ptrs(double target[], double source[], double*pointer)
{
	int i = 0;
	for (i = 0; source + i != pointer; i++)
	{
		target[i] = source[i];
	}
}

void reversal(double arr[], double arr2[], int length)
{
	int i;

	
	for (i = 0; i < length; i++)
	{
		arr2[length - 1 - i] = arr[i];
	}
}

double average(double arr[], int n)
{
	int i = 0;
	double sum = 0;
	double avg = 0;
	for (i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	avg = sum / n;
	return avg;
}

double max(double a, double b)
{
	double maximum;
	if (a > b)
		maximum = a;
	else
		maximum = b;
	return maximum;
}