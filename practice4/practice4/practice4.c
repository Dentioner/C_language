#include<stdio.h>
#include<float.h>
int main()
{	
	/*
	char fn[10];
	char ln[10];
	int fnlength;
	int lnlength;
	
	float number;
	char name[20];
	float height;
	
	float speed;
	float time;
	
	float a;
	double b;
*/
	float goal;
	float fuel;
	/*T1
	printf("Please input your first & last name.\n");
	printf("First Name is:");
	scanf("%s", fn);
	printf("\nLast Name is:");
	scanf("%s", ln);

	printf("\nSo, your name is %s, %s.", fn, ln);
*/
	/*
	T2
	printf("Please input your first & last name.\n");
	printf("First Name is:");
	scanf("%s", fn);
	printf("\nLast Name is:");
	scanf("%s", ln);
	fnlength = strlen(fn) + 3;
	lnlength = strlen(ln) + 3;
	
	printf("\na. So, your name is %s %s.", fn, ln);	
	printf("\nb. So, your name is %20s %20s.", fn, ln);
	printf("\nc. So, your name is %-20s %-20s", fn, ln);
	printf("\nd. So, your name is %*s %*s", fnlength, fn, lnlength, ln);
	*/
	/*T3
	printf("Please input a number.\n");
	scanf("%f", &number);
	printf("\na. The input is %3.1f or %2.1e.\n", number, number);
	printf("b. The input is %+5.3f or %4.3E.", number, number);
	*/
/*
T4
	printf("Please input your name.\n");
	scanf("%s", name);
	
	printf("Please input your height.\n");
	scanf("%f", &height);
	printf("%s, you are %.3f feet tall.", name, height);
	*/
/*T5	
	printf("���ٶ��٣�\n");
	scanf("%f", &speed);
	printf("At %.2f megabits per second, a file of 2.20 megabytes\n", speed);
	time = (8*2.20)/speed;
	printf("downloads in %.2f seconds", time);
	*/
/*T6
	printf("Please input your first & last name.\n");
	printf("First Name is:");
	scanf("%s", fn);
	getchar();
	getchar();
	printf("\nLast Name is:");
	scanf("%s", ln);	
	getchar();
	getchar();

	fnlength = strlen(fn);
	lnlength = strlen(ln);

	printf("%*s %*s\n", fnlength, fn, lnlength, ln);
	printf("%*d %*d\n", fnlength, fnlength, lnlength, lnlength);
	printf("%-*d %-*d", fnlength, fnlength, lnlength, lnlength);
*/
	/*T7
	a = 1.0/3.0;
	b = 1.0/3.0;
	printf("%d\t%d\n", FLT_DIG, DBL_DIG);
	printf("6: %.6f\t%.6lf\n", a, b);
	printf("12��%.12f\t%.12lf\n", a, b);
	printf("16: %.16f\t%.16lf\n", a, b);
*/
	printf("��������̺����ĵ�������:\n");

	printf("���(Ӣ��)��");

	scanf("%f\n", &goal);
	/*Ϊʲô����س���Ҫ�ఴһ�£�*/

	printf("������(����)��");

	scanf("%f\n", &fuel);


	printf("�൱��%.1fӢ��������%.1f���ص���\n", goal, fuel);
	printf("��λӢ��Ĺ�����%.1f\n", fuel/goal);
	printf("�൱��%.1fӢ��������%.1f���ص���\n", goal*1.609, fuel*3.785);
	printf("ÿ100km�Ĺ���Ϊ%.1f\n", goal*160.9/(fuel*3.785));
	
	
	
	
	system("pause");
	return 0;



}