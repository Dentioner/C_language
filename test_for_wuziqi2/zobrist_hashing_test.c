#include <stdio.h>
#include <stdlib.h>

#define NN 312
#define MM 156
#define MATRIX_A 0xB5026F5AA96619E9ULL
#define UM 0xFFFFFFFF80000000ULL /* Most significant 33 bits */
#define LM 0x7FFFFFFFULL         /* Least significant 31 bits */

/* The array for the state vector */
static unsigned long long mt[NN];
/* mti==NN+1 means mt[NN] is not initialized */
static int mti = NN + 1;

unsigned long long ZobristTable[15][15][2];

/* initializes mt[NN] with a seed */
void init_genrand64(unsigned long long seed)
{
    mt[0] = seed;
    for (mti = 1; mti < NN; mti++)
        mt[mti] = (6364136223846793005ULL * (mt[mti - 1] ^ (mt[mti - 1] >> 62)) + mti);
}
/* generates a random number on [0, 2^64-1]-interval */
unsigned long long genrand64_int64(void)
{
    int i;
    unsigned long long x;
    static unsigned long long mag01[2] = {0ULL, MATRIX_A};

    if (mti >= NN)
    { /* generate NN words at one time */

        /* if init_genrand64() has not been called, */
        /* a default initial seed is used     */
        if (mti == NN + 1)
            init_genrand64(5489ULL);

        for (i = 0; i < NN - MM; i++)
        {
            x = (mt[i] & UM) | (mt[i + 1] & LM);
            mt[i] = mt[i + MM] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
        }
        for (; i < NN - 1; i++)
        {
            x = (mt[i] & UM) | (mt[i + 1] & LM);
            mt[i] = mt[i + (MM - NN)] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];
        }
        x = (mt[NN - 1] & UM) | (mt[0] & LM);
        mt[NN - 1] = mt[MM - 1] ^ (x >> 1) ^ mag01[(int)(x & 1ULL)];

        mti = 0;
    }

    x = mt[mti++];

    x ^= (x >> 29) & 0x5555555555555555ULL;
    x ^= (x << 17) & 0x71D67FFFEDA60000ULL;
    x ^= (x << 37) & 0xFFF7EEE000000000ULL;
    x ^= (x >> 43);

    return x;
}

int indexOf(char W_B)
{
    //'o' represent white,'x' represent black
    if (W_B == 'o')
    {
        return 0;
    }
    else if (W_B == 'x')
    {
        return 1;
    }
}

void initTable()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ZobristTable[i][j][k] = genrand64_int64();
            }
        }
    }
}

unsigned long long computeHash(char board[15][16])
{
    unsigned long long h = 0;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (board[i][j] != '-')
            {
                int W_B = indexOf(board[i][j]);
                h ^= ZobristTable[i][j][W_B];
            }
        }
    }
    return h;
}
int main(void)
{
    char board[15][16] = {
        "---------------",
        "---------------",
        "-----x-o-------",
        "-----o-x-------",
        "---------------",
        "---------------",
        "---------------",
        "---------------",
        "---------------",
        "---------------",
        "---------------",
        "---------------",
        "---------------",
        "---------------",
        "---------------"};
    initTable();
    unsigned long long hashValue = computeHash(board);
    printf("The hash value is  : %llu\n", hashValue);
    //Move the 'x' to the board[1][5]
    char piece = board[2][5];
    board[2][5] = '-';
    hashValue ^= ZobristTable[2][5][indexOf(piece)];
    board[1][5] = piece;
    hashValue ^= ZobristTable[1][5][indexOf(piece)];
    printf("The new hash vlaue is  : %llu\n", hashValue);
    //restore the 'x' to the board[2][5]
    piece = board[1][5];
    board[1][5] = '-';
    hashValue ^= ZobristTable[1][5][indexOf(piece)];
    board[2][5] = piece;
    hashValue ^= ZobristTable[2][5][indexOf(piece)];
    printf("after restore step, the hash vlaue is  : %llu\n", hashValue);
    system("pause");
    return 0;
}
