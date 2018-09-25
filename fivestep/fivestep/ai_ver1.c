#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define Consecutive_Five 10000000//����
#define Open_Four 1000000//����
#define Open_Three 100000//����
#define Gapped_Two_Two 100050//�������ֶ��ǳ��ģ�����������2��֮��ȱ��һ����  ��񣿡��
#define Capped_Four 100050//���ֳ�����һͷ����ס�ĳ���   ������
#define Gapped_Four 100050//���ֳ�����һ��������һ����������֮�����һ��  ��?����
#define Gapped_Three 100000//���������������������Ǽ����γɻ��ĵ�����  �񣿡��
#define Capped_Three 10000//�����������ֻ���γɳ���  �����

long int evaluation(char board[][17][2], int step_count, bool my_turn,
	int raw, int column)
//step_count�������ǣ�ȷ�������Ǻ��ӻ��ǰ���
//my_turn �������ǣ�ȷ���������ҷ����ǵз�
//raw��column�Ǵ������꣬�����������ĸ�λ����Ҫ����
{
//��ȷ������ǰ����»��Ǻ�����
	char *chess;
	char *opponent_chess;
	char black[2] = "��";
	char white[2] = "��";
	
	long int value = 0;
	if (step_count % 2)//���step����������2�Ļ������ǰ���
	{
		chess = white;
		opponent_chess = black;
	}
	else
	{
		chess = black;
		opponent_chess = white;
	}

//�������
	//ˮƽ����
		//�����?��
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}
		//����?����
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//���?�����
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//��?������
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//?�������
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

	//��ֱ����
		//�����?��
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}
		
		//����?����
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//���?�����
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//��?������

	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//?�������
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

	//�������·���
		//�����?��

	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//����?����
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//���?�����
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//��?������
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//?�������
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

	//�������·���
		//�����?��
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//����?����
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//���?�����
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}

		//��?������
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}
		
		//?�������
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) == 0))
	{
		value += Consecutive_Five;
	}


//������
	//ˮƽ����
		//_?����_��
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw][column + 4], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}
		
		//_��?���_��
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column - 2], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_���?��_��
	if ((strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw][column - 3], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_����?_��
	if ((strncmp(board[raw][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw][column - 4], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

	//��ֱ����
		//_?����_��
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_��?���_��

	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_���?��_��
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_����?_��
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

	//����������
		//_?����_��
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column - 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column + 4], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_��?���_��
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_���?��_��
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column - 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column + 2], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_����?_��
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column - 4], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

	//����������
		//_?����_��
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) == 0)
		&& (strncmp(board[raw + 4][column + 4], chess, 2) != 0)
		&& (strncmp(board[raw + 4][column + 4], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column - 1], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_��?���_��
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw + 3][column + 3], chess, 2) != 0)
		&& (strncmp(board[raw + 3][column + 3], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column - 2], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_���?��_��
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column + 2], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) != 0)
		&& (strncmp(board[raw - 3][column - 3], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

		//_����?_��
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw - 3][column - 3], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column + 1], opponent_chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], chess, 2) != 0)
		&& (strncmp(board[raw - 4][column - 4], opponent_chess, 2) != 0))
	{
		value += Open_Four;
	}

//����
	//ˮƽ����
		//
}





