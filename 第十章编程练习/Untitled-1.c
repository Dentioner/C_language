#include<stdio.h>
void copy_arr(double[], double[], int n);
void copy_ptr(double*, double*, int n);
void copy_ptrs(double[], double[], double *);
void reversal(double[],  int n);
int main()
{

    double arr[]={1,2,3,4,5,6};
    double arr2[6];
    reversal()
 


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

void reversal(double arr[], int length)
{
	int i;

	
	double arr2[length];
	for (i = 0; i < length; i++)
	{
        arr2[length - 1 -i]=arr[i];
	}
    return;
}