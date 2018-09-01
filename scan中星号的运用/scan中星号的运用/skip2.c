#include<stdio.h>
int main()
{
	int n;

	printf("Please enter three integers:\n");
	scanf("%*d %*d %d", &n);/*scanf 中如果使用了星号，就会使得那个%d被忽略*/
	printf("The last integer was %d\n", n);
	
	system("pause");
	return 0;
}