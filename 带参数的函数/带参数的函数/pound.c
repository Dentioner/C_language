#include<stdio.h>
void pound(int n);
int main()
{
	int times = 5;
	char ch = '!';/*in ASCII, !=33*/
	float f = 6.0f;
	
	pound(times);
	pound(ch);//�൱��pound((int)ch)
	pound(f);//�൱��pound((int)f)

	system("pause");
	return 0;
}

void pound(int n)
{
	while (n-- > 0)
		printf("#");
	printf("\n");
}