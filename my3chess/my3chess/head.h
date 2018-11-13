#define FLOOR 3

//ÿ�θ���FLOOR����Ҫ��board.c�е�priority, best_score_of_upper, not_in_the_same_branch����������Ĵ�С��һ��
#define Consecutive_Five 10000000//����
#define Open_Four 1000000//����
#define Open_Three 100000//����
#define Gapped_Two_Two 100050//�������ֶ��ǳ��ģ�����������2��֮��ȱ��һ����  ��񣿡��
#define Capped_Four 100050//���ֳ�����һͷ����ס�ĳ���   ������͡�����
#define Gapped_Four 100050//���ֳ�����һ��������һ����������֮�����һ��  ��?����
#define Gapped_Three 99950//���������������Ǽ����γɻ��ĵ���  �񣿡��
#define Capped_Three 10000//����, ���ֻ���γɳ���  �����
//��Ҫ�����Ĵ���� ���1000��
/*����һ�����⼸����̬��
1. �����__
2. ����_��_
3. ���_���_
4. ���__��
5. ��_��_��
6. ��_����_��
*/
#define Open_two 1000//����
#define depth_of_hashing 100000
void DrawBoard(char board[][3][3], int i, long int value, int mode_choice, int coordinate[], int step_count);

bool judgement(char board[][3][3], int step_count);
long int evaluation(char board[][3][3], int step_count, bool my_turn, int raw, int column);
void get_coordinate(int coordinate[], char board[][3][3], int step_count);
void chess_play_ver2(char board[][3][3], int step_count, int coordinate[]);
long int Minimax2(char board[][3][3], int step_count, bool my_turn, bool ai_first, int floor, int coordinate[]);
void auto_play(char board[][3][3], char chess[], char opponent_chess[], int coordinate[]);
