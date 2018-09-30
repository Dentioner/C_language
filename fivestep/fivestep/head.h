#define FLOOR 1
void DrawBoard(char board[][17][2], int i, long int value, int mode_choice);
void chess_play(char **board, int step_count);
bool judgement(char board[][17][2], int step_count);
long int evaluation(char board[][17][2], int step_count, bool my_turn, int raw, int column);
void get_coordinate(int coordinate[], char board[][17][2], int step_count);
void chess_play_ver2(char board[][17][2], int step_count, int coordinate[]);
long int Minimax2(char board[][17][2], int step_count, bool my_turn, bool ai_first, int floor, int coordinate[], long int best_score_of_upper);
void auto_play(char board[][17][2], char chess[], char opponent_chess[]);
bool verify_coordinate(char board[][17][2], int raw, int column, char chess, char opponent_chess);

