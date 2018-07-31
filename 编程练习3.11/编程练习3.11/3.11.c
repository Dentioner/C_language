#include<stdio.h>
void t2(void);
void t3(void);
void t4(void);
void t5(void);
void t2(void)
{
	int code;
	printf("请输入一个ASCII码的编号：");
	scanf("%d", &code);
	printf("对应的ASCII码为%c\n", code);
}



void t3(void)
{
	printf("\a");
	printf("Started by the sudden sound, Sally shouted,\n");
	printf("\"By the Great Pumpkin, what was that?\"");
}




void t4(void)
{
	float a;
	printf("Enter a floating-point value: ");
	scanf("%f", &a);
	printf("\nfixed-point notation: %f\n", a);
	printf("expoential notation: %e\n", a);
	printf("p notation: %a\n", a);
}
void t5(void)
{
	double age;
	printf("你多大了？\n");
	scanf("%d", &age);
	printf("相当于%d秒了\n", age*3.156e7);
}

main()
{
	/*t2();
	t3();
	t4();*/
	t5();
	system("pause");
	return 0;
}
 