#define FLOOR 3
#define Consecutive_Five 10000000//连五
#define Open_Four 1000000//活四
#define Open_Three 100000//活三
#define Gapped_Two_Two 100050//下面三种都是冲四，这种是两个2子之间缺了一个子  ●●？●●
#define Capped_Four 100050//这种冲四是一头被堵住的冲四   ○●●●●和●●●●○
#define Gapped_Four 100050//这种冲四是一个活三与一个单独的子之间空了一格  ●?●●●
#define Gapped_Three 100000//这种是跳活三，是即将形成活四的三  ●？●●
#define Capped_Three 10000//眠三, 最多只能形成冲四  ○●●●
//需要连二的打分吗？ 大概1000分

/*眠三一共有这几种形态：
1. ○●●●__
2. ○●●_●_
3. ○●_●●_
4. ●●__●
5. ●_●_●
6. ○_●●●_○
*/

void DrawBoard(char board[][17][2], int i, long int value, int mode_choice);
void chess_play(char **board, int step_count);
bool judgement(char board[][17][2], int step_count);
long int evaluation(char board[][17][2], int step_count, bool my_turn, int raw, int column);
void get_coordinate(int coordinate[], char board[][17][2], int step_count);
void chess_play_ver2(char board[][17][2], int step_count, int coordinate[]);
long int Minimax2(char board[][17][2], int step_count, bool my_turn, bool ai_first, int floor, int coordinate[], long int best_score_of_upper[], int priority[][26][2]);
void auto_play(char board[][17][2], char chess[], char opponent_chess[]);
bool verify_coordinate(char board[][17][2], int raw, int column, char chess, char opponent_chess);
bool before_evaluation(char board[][17][2], int priority[][26][2], int floor, int step_count, bool my_turn);

