#include<stdio.h>
#include<string.h>
#include<math.h>
//#include <typeinfo.h>
int main()
{/*T1
	char alphabet[26];
	int i;
	char alpha = 'a';
	for (i = 0; i < 26; i++)
	{
		alphabet[i] = alpha;
		alpha++;
		printf("%c", alphabet[i]);

	}


	T2
	int i,j;
	for (i = 1; i < 6; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("$");
		}
		printf("\n");
	}
	
	T3
	char i;
	int j,k;
	for (j = 1; j < 7; j++)
	{
		for (i = 'F', k=0; k < j; k++)
		{
			printf("%c", i-k);
			
		}
		printf("\n");
	}
	
T4
	int i,j;
	char ch = 'A';
	for (i = 1; i < 7; i++)
	{
		for (j = 0; j < i; j++)
		{
			
			printf("%c", ch);
			ch ++;
		}
		printf("\n");
	}

T5
	char input;
	char initial = 'A';
	int i;//i�ǵڼ���
	int hang;//��������ܹ�������
	int j;//ÿһ�еĿո���
	int k;//ÿһ�е���ĸ��
	
	printf("please input a character.\n");
	scanf("%c", &input);

	hang = (int)input - (int)initial + 2;
	
	for (i = 1; i < hang; i++)
	{
		for (j = 0; j < hang - 1 -i; j++)
		{
			printf(" ");
		}
		for (k = 0; k < i; k++)
		{
			printf("%c", initial + k);
		}
		for (k = i-1; k > 0; k--)
		{
			printf("%c", initial + k -1);
		}



		printf("\n");
	}
*/
	/*T7
	char word[20];//ע��word�����б�list�������飬֮ǰ��Python�����õ�list����������������word��ÿ��λ��ֻ�ܴ�һ���ַ���С�Ķ�����
	char ch;
	int i;
	printf("please input a word.\n");
	/*for (i = 0; i < 5; i++)
	{
		scanf("%c", &word[i]);
		//printf("%c", word[i]);
	}*/
	/*
	scanf("%s", &word);
	//��%s�Ļ���scanf���Լ�������ĵ��ʣ�һ����ĸһ����ĸ�����뵽word���棬���������%c�Ļ���scanf��ֻ����һ����ĸ��word[0]�У���Ҫѭ������ʵ��
	for (i = strlen(word)-1; i >= 0; i--)
	{
		printf("%c", word[i]);
	}

	*/

/*T8
	float a,b,c,d;
	int p;
	do
	{	
		//printf("test==============================================");
		printf("please input a number for a.\n");
		p = scanf("%f", &a);
		fflush(stdin);//�������ȱ��
	}
	while (p != 1);
	
	/*for (p = 0; p != 1; p = scanf("%f", &a))
	{
		printf("please input a number for a.\n");
		getchar();

	}
	*/
/*
	do
	{	

		printf("please input a number for b.\n");
		p = scanf("%f", &b);
		fflush(stdin);
	}
	while (p != 1);
	
	c = a-b;
	d = a*b;
	printf("=%f", c/d);

*/

/*T12
	double sequence = 0;
	double element = 0;
	double fenmu;
	int length;
	//double fuhao = -1.0;
	int p;
	do
	{	
		printf("������ļ�����ͣ�\n");
		p = scanf("%d", &length);
		fflush(stdin);
	}
	while (p != 1);
	//printf("test0\n");
	for (fenmu = 1.0; (int)fenmu < length+1; fenmu++)
	{	
	//	printf("test1\n");
		element = 1.0/fenmu;
	//	printf("test2\n");
	//	element *= pow(fuhao, fenmu-1.0);
	//	printf("test3\n");
		sequence += element;
	//	printf("%f\n", element);
	}

	printf("finally, it is %lf\n", sequence);
	printf("Eular const is %lf\n", sequence - log(fenmu));
*/

	char in[256];
	//char enter;
	int i = 0;
	int j;
	printf("?\n");
	do
	{
		scanf("%c", &in[i]);
		printf("test.\n");//����ѭ�����˼���
		i++;
	}
	while (in[i-1] != '\n');
	printf("\n%d\n", strlen(in));
	//printf("%s", in);
	for (j =i;j>-1 ;j--)
	{
		printf("%c", in[j]);
	}
	system("pause");
	return 0;
}
