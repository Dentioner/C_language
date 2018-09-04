#include<stdio.h>
void pound(int n);
int main()
{
	int times = 5;
	char ch = '!';/*in ASCII, !=33*/
	float f = 6.0f;
	
	pound(times);
	pound(ch);//相当于pound((int)ch)
	pound(f);//相当于pound((int)f)

	system("pause");
	return 0;
}

void pound(int n)
{
	while (n-- > 0)
		printf("#");
	printf("\n");
}