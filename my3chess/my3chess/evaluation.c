#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include"head.h"
//��̬�Ķ����https://www.cnblogs.com/songdechiu/p/5768999.html
//https://baike.1688.com/doc/view-d3091513.html



long int evaluation(char board[][3][3], int step_count,
	bool my_turn, int raw, int column)
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
			//���?��
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) == 0)
		&&(column - 2 >= 0 ))//��һ����Ҫ�޸ĵ��������У���BUG��
	{
		value += Consecutive_Five;
	}
	//��?����
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		
		&& (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (column - 1 >= 0) && (column + 1  <= 2))
	{
		value += Consecutive_Five;
	}

	//?�����
	if ( (strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 2], chess, 2) == 0)
		&& (column + 2 <= 2))
	{
		value += Consecutive_Five;
	}

	

	//��ֱ����
		//���?��
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (raw - 2 >= 0))
	{
		value += Consecutive_Five;
	}

	//��?����
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (raw - 1 >= 0) && (raw + 1 <= 2))
	{
		value += Consecutive_Five;
	}

	//?�����
	if ( (strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (raw + 2 <= 2))
	{
		value += Consecutive_Five;
	}

	
	//�������·���
		//���?��

	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column - 2], chess, 2) == 0)
		&& (raw + 2 <= 2) && (column - 2 >= 0))
	{
		value += Consecutive_Five;
	}

	//��?����
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (raw + 1 <= 2) && (column - 1 >= 0)
		&& (raw - 1 >= 0) && (column + 1 <= 2))
	{
		value += Consecutive_Five;
	}

	//?�����
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column + 2], chess, 2) == 0)
		&& (raw - 2 >= 0) && (column + 2 <= 2))
	{
		value += Consecutive_Five;
	}

	

	//�������·���
		//���?��
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column - 2], chess, 2) == 0)
		&& (raw - 2 >= 0) && (column - 2 >= 0))
	{
		value += Consecutive_Five;
	}

	//��?����
	if ((strncmp(board[raw - 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (raw - 1 >= 0) && (column - 1 >= 0)
		&& (raw + 1 <= 2) && (column + 1 <= 2))
	{
		value += Consecutive_Five;
	}

	//?�����
	if (
		(strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column + 2], chess, 2) == 0)
		
		&& (raw + 2 <= 2) && (column + 2 <= 2))
	{
		value += Consecutive_Five;
	}

	
	

	//����?_������һ�ַ�����������棬������дһ�ַ���
		// ˮƽ����
			// ��?_
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (column + 1 <= 2)&&(column  - 1>=0))
		
	{
		value += Capped_Four;
	}

	// ?��_
	if ((strncmp(board[raw][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw][column+2], chess, 2) != 0)
		&& (strncmp(board[raw][column+2], opponent_chess, 2) != 0)
		&& (column + 2 <= 2))
		
	{
		value += Capped_Four;
	}
	// ��_?
	if ((strncmp(board[raw][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (column - 2 >= 0))

	{
		value += Capped_Four;
	}
	// ?_��
	if ((strncmp(board[raw][column +2], chess, 2) == 0)
		&& (strncmp(board[raw][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw][column + 1], opponent_chess, 2) != 0)
		&& (column + 2 <= 2) )

	{
		value += Capped_Four;
	}
	// _��?
	if ((strncmp(board[raw][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw][column -2], opponent_chess, 2) != 0)
		&& (column - 2 >= 0))
	{
		value += Capped_Four;
	}
	// _?��
	if ((strncmp(board[raw][column +1], chess, 2) == 0)
		&& (strncmp(board[raw][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw][column - 1], opponent_chess, 2) != 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))

	{
		value += Capped_Four;
	}
	//��ֱ����
			// ��?_
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0))

	{
		value += Capped_Four;
	}

	// ?��_
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column], opponent_chess, 2) != 0)
		&&(raw + 2 <= 2))

	{
		value += Capped_Four;
	}
	// ��_?
	if ((strncmp(board[raw - 2][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw- 1][column], opponent_chess, 2) != 0)
		&& (raw -2 >= 0))

	{
		value += Capped_Four;
	}
	// ?_��
	if ((strncmp(board[raw + 2][column], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2))

	{
		value += Capped_Four;
	}
	// _��?
	if ((strncmp(board[raw - 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0))
	{
		value += Capped_Four;
	}
	// _?��
	if ((strncmp(board[raw + 1][column], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0))

	{
		value += Capped_Four;
	}

	//�������·���
		// ��?_
	if ((strncmp(board[raw + 1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw - 1 ][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column + 1], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))

	{
		value += Capped_Four;
	}

	// ?��_
	if ((strncmp(board[raw - 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw -2][column + 2], chess, 2) != 0)
		&& (strncmp(board[raw -2][column + 2], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0)
		&& (column + 2 <= 2))

	{
		value += Capped_Four;
	}
	// ��_?
	if ((strncmp(board[raw+2][column - 2], chess, 2) == 0)
		&& (strncmp(board[raw+1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw+1][column - 1], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2) 
		&& (column - 2 >= 0))

	{
		value += Capped_Four;
	}
	// ?_��
	if ((strncmp(board[raw-2][column + 2], chess, 2) == 0)
		&& (strncmp(board[raw-1][column + 1], chess, 2) != 0)
		&& (strncmp(board[raw-1][column + 1], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0)
		&& (column + 2 <= 2))

	{
		value += Capped_Four;
	}
	// _��?
	if ((strncmp(board[raw+1][column - 1], chess, 2) == 0)
		&& (strncmp(board[raw+2][column - 2], chess, 2) != 0)
		&& (strncmp(board[raw+2][column - 2], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2)
		&& (column - 2 >= 0))
	{
		value += Capped_Four;
	}
	// _?��
	if ((strncmp(board[raw-1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw+1][column - 1], chess, 2) != 0)
		&& (strncmp(board[raw+1][column - 1], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))

	{
		value += Capped_Four;
	}

	//�������·���
		
			// ��?_
	if ((strncmp(board[raw - 1][column -1], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column+1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column+1], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))

	{
		value += Capped_Four;
	}

	// ?��_
	if ((strncmp(board[raw + 1][column + 1], chess, 2) == 0)
		&& (strncmp(board[raw + 2][column+2], chess, 2) != 0)
		&& (strncmp(board[raw + 2][column+2], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2)
		&& (column + 2 <= 2))

	{
		value += Capped_Four;
	}
	// ��_?
	if ((strncmp(board[raw - 2][column-2], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column-1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column-1], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0)
		&& (column - 2 >= 0))

	{
		value += Capped_Four;
	}
	// ?_��
	if ((strncmp(board[raw + 2][column+2], chess, 2) == 0)
		&& (strncmp(board[raw + 1][column+1], chess, 2) != 0)
		&& (strncmp(board[raw + 1][column+1], opponent_chess, 2) != 0)
		&& (raw + 2 <= 2)
		&& (column + 2 <= 2))

	{
		value += Capped_Four;
	}
	// _��?
	if ((strncmp(board[raw - 1][column-1], chess, 2) == 0)
		&& (strncmp(board[raw - 2][column-2], chess, 2) != 0)
		&& (strncmp(board[raw - 2][column-2], opponent_chess, 2) != 0)
		&& (raw - 2 >= 0)
		&& (column - 2 >= 0))
	{
		value += Capped_Four;
	}
	// _?��
	if ((strncmp(board[raw + 1][column+1], chess, 2) == 0)
		&& (strncmp(board[raw - 1][column-1], chess, 2) != 0)
		&& (strncmp(board[raw - 1][column-1], opponent_chess, 2) != 0)
		&& (raw + 1 <= 2) && (raw - 1 >= 0)
		&& (column + 1 <= 2) && (column - 1 >= 0))
		

	{
		value += Capped_Four;
	}

	//���������������Է��ķ����������Ϊ��
	//���ڵ������ǣ���������Ǽ����Է�����һ�Σ�����һ���������潫˫��������һ�Σ�
	//Ŀǰ�Ĵ����ǣ���������������Է�����һ�Σ��ò�����my_turn����

	if (my_turn)
	{
		;
	}
	else
	{
		value *= -1;
	}
	return value;

}





