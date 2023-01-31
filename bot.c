#include "function.h"

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int checkWin(int** board)
{
    if(koniec(board) == 1)
    {
        return 10;
    }

    if(koniec(board) == 2)
    {
        return -10;
    }

    if(koniec(board) == 3)
    {
        return 0;
    }
    
    else
    {
        return INT_MIN;
    }
}
int minimax(int** board, int depth, int isMaximizing)
{
    int result = checkWin(board);
    if(result != INT_MIN)
    {
        return result;
    }
    int** temp = create_matrix(board);
    
    if(isMaximizing == 1)
    {
        int bestscore = INT_MIN;
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(check(temp, i, j))
                {
                    temp[i][j] = 1;
                    int score = minimax(board, depth+1, 0);
                    temp[i][j] = 0;
                    bestscore = max(score, bestscore);
                }
            }
        }
        return bestscore;
    }
    else
    {
        int bestscore = INT_MAX;
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(check(temp, i, j))
                {
                    temp[i][j] = 2;
                    int score = minimax(board, depth+1, 1);
                    temp[i][j] = 0;
                    bestscore = min(score, bestscore);
                }
            }
        }
        return bestscore;
    }
}

pair best_move(int** board)
{
    int bestscore = INT_MAX;
    pair move;
    int** temp = create_matrix(board);
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(check(temp, i, j))
            {
                temp[i][j] = 2;
                int score = minimax(temp, 0, 0);
                temp[i][j] = 0;
                if(score < bestscore)
                {
                    score = bestscore;
                    move.x = i;
                    move.y = j;
                }
            }
        }
    }
    return move;
}