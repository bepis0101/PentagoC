#include <stdio.h>
#include <stdlib.h>
typedef struct pair
{
    int x;
    int y;
}pair;

int max(int a, int b);

int min(int a, int b);

int checkWin(int** board);

int minimax(int** board, int depth, int isMaxmimizing);

pair best_move(int **board);