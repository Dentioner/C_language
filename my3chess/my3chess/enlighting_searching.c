#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include"head.h"


//����ʽ�������������ȼ�˳�򣬶Է�֧����������߼�֦�ٶ�
//��https://github.com/lihongxun945/gobang/blob/master/src/ai/board.js
int before_evaluation(char board[][3][3],  
	int step_count, bool my_turn)
	//step_count�������ļ����β���������evaluation��
{
	int my_raw = 0;
	int my_column = 0;
	char black[2] = "��";
	char white[2] = "��";
	long int my_value = 0;
	long int opponent_value = 0;
	int status = 0;
	//0��ʾ��ǰ�������
	//1��ʾ��ǰ��ַ����ҷ�ɱ��
	//2��ʾ��ǰ���û�з����ҷ�ɱ�֣����Ƿ��ֶԷ�ɱ��
	bool find_five = false;
	bool find_opponent_five = false;
	
	
	bool final_hit = false;//�����ҷ�����ֱ�ӷ���
	//�ȳ�ʼ������֮ǰ��ķ�֧�ù��ļ�¼��Ϊ0

	
	//���濪ʼ��ʽ��¼
	for (my_raw = 0; my_raw < 3; my_raw++)
	{
		for (my_column = 0; my_column < 3; my_column++)
		{
			if ((strncmp(board[my_raw][my_column], black, 2) != 0)
				&& (strncmp(board[my_raw][my_column], white, 2) != 0))
			{
				my_value = evaluation(board, step_count, my_turn, my_raw, my_column);
				my_value = labs(my_value);
				if (my_value >= Consecutive_Five)//����������ҷ�����ĵط�
				{
					status = 1;
					return status;
				}
				
				

			}

		} 




	}


	for (my_raw = 0; my_raw < 3; my_raw++)
	{
		for (my_column = 0; my_column < 3; my_column++)
		{
			if ((strncmp(board[my_raw][my_column], black, 2) != 0)
				&& (strncmp(board[my_raw][my_column], white, 2) != 0))
			{
				opponent_value = evaluation(board, step_count + 1, !my_turn, my_raw, my_column);
				opponent_value = labs(opponent_value);
				if (opponent_value >= Consecutive_Five)//��������˶Է�����ĵط�
				{
					status = 2;
					return status;
				}


			}

		}




	}


	return status;
}