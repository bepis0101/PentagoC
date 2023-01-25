#include "function.h"

plansza pusta(plansza x)
{
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            x.t[i][j] = 0;
        }
    } // wprowadzenie pustej planszy 

    return x;
}
char zamien(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        c = c-'a'+'A';
    }
    return c;
}
int check(int** tab, int i, int j)
{
    if(tab[i][j] == 0)
    {
        return 1;
    }
    return 0;
} 
int** k_czarnych(int** tab, int i, int j)
{
    tab[i][j] = 1;
    return tab;
}
int** k_bialych(int** tab, int i, int j)
{
    tab[i][j] = 2; // ustalamy ze dwojki beda biale
    return tab;
}
plansza obrot_r(plansza x) // obrot w prawo 
{
    plansza temp;
    temp = pusta(temp);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 2; j >= 0; j--)
        {
            temp.t[abs(2-j)][i] = x.t[i][j];
        }
    }

    return temp;
}
plansza obrot_l(plansza x)
{
    plansza temp;
    temp = pusta(temp);    
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 3; i++)
        {
            temp.t[j][2-i] = x.t[i][j];
        }
    }
    return temp;
}

int** fill(int** tab, int val, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tab[i][j] = val;
        }
    }
    return tab;
}
int** rewrite(plansza P[], int** tab)
{
    for(int y = 0; y < 3; y++)
    {
        for(int x = 0; x < 3; x++)
        {
            tab[x][y] = P[0].t[x][y];
            tab[x+3][y] = P[1].t[x][y];
            tab[x][y+3] = P[2].t[x][y];
            tab[x+3][y+3] = P[3].t[x][y];
        }
    }
    return tab;
}
plansza* rewrite_b(plansza P[], int** tab)
{
    for(int y = 0; y < 3; y++)
    {
        for(int x = 0; x < 3; x++)
        {
            P[0].t[x][y] = tab[x][y];
            P[1].t[x][y] = tab[x+3][y];
            P[2].t[x][y] = tab[x][y+3];
            P[3].t[x][y] = tab[x+3][y+3];
        }
    }
    return P;
}

{
    putchar('\n');
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < length; x++)
        {
            printf("%3d", tab[x][y]);
        }
        putchar('\n');
    }
}

int check_vertical(int** board)
{
    for(int i = 0; i < 6; i++)
    {
        int check = 1;
        if(board[i][0] == 1)
        {
            for(int j = 1; j < 5; j++)
            {
                if(board[i][j] != 1)
                {
                    check = 0;
                    break;
                }
            }
            if(check == 1) 
            return 1;
        }
        else if(board[i][1] == 1)
        {
            check = 1;
            for(int j = 2; j < 6; j++)
            {
                if(board[i][j] != 1)
                {
                    check = 0;
                    break;
                }
            }
            if(check == 1)
            return 1;
        }
        check = 1;
        if(board[i][0] == 2)
        {
            for(int j = 1; j < 5; j++)
            {
                if(board[i][j] != 2)
                {
                    check = 0;
                    break;
                }
            }
            if(check == 1)
            return 2;
        }
        else if(board[i][1] == 2)
        {
            check = 1;
            for(int j = 2; j < 6; j++)
            {
                if(board[i][j] != 2)
                {
                    check = 0;
                    break;
                }
            }
            if(check == 1)
            return 2;
        }
    }
    return 0;
}
int check_horizontal(int** board)
{
    for(int i = 0; i < 6; i++)
    {
        int check = 1;
        if(board[0][i] == 1)
        {
            for(int j = 1; j < 5; j++)
            {
                if(board[j][i] != 1)
                {
                    check = 0;
                    break;
                }
            }
            if(check == 1)
            return 1;
        }
        else if(board[1][i] == 1)
        {
            check = 1;
            for(int j = 2; j < 6; j++)
            {
                if(board[j][i] != 1)
                {
                    check = 0;
                    break;
                }
            }
            if(check == 1)
            return 1;
        }
        check = 1;
        if(board[0][i] == 2)
        {
            for(int j = 1; j < 5; j++)
            {
                if(board[j][i] != 2)
                {
                    check = 0;
                    break;
                }
            }
            if(check == 1)
            return 2;
        }
        else if(board[1][i] == 2)
        {
            check = 1;
            for(int j = 2; j < 6; j++)
            {
                if(board[j][i] != 2)
                {
                    check = 0;
                    break;
                }
            }
            if(check == 1)
            return 2;
        }
    }
    return 0;
}

int check_diagonal(int** board)
{
    int x = 0;
    if(board[0][0] != 0)
    {
        x = board[0][0];
        for(int i = 1; i < 5; i++)
        {
            if(board[i][i] != x)
            {
                x = 0;
                break;
            }
        }
        if(x != 0) return x;
    }
    if(board[5][0] != 0)
    {
        x = board[5][0];
        for(int i = 4; i > 0; i--)
        {
            if(board[i][5-i] != x)
            {
                x = 0;
                break;
            }
        }
        if(x != 0) return x;
    }

    if(board[1][0] != 0)
    {
        x = board[1][0];
        for(int i = 1; i < 5; i++)
        {
            if(board[i+1][i] != x)
            {
                x = 0;
                break;
            }
        }
        if(x != 0) return x;
    }
    if(board[4][0] != 0)
    {
        x = board[4][0];
        for(int i = 4; i > 0; i--)
        {
            if(board[i-1][5-i] != x)
            {
                x = 0;
                break;
            }
        }
        if(x != 0) return x;
    }

    if(board[0][1] != 0)
    {
        x = board[0][1];
        for(int i = 1; i < 5; i++)
        {
            if(board[i][i+1] != x)
            {
                x = 0;
                break;
            }
        }
        if(x != 0) return x;
    }
    if(board[1][1] != 0)
    {
        x = board[1][1];
        for(int i = 2; i <= 5; i++)
        {
            if(board[i][i] != x)
            {
                x = 0;
                break;
            }
        }
        if(x != 0) return x;
    }
    if(board[5][1] != 0)
    {
        x = board[5][1];
        for(int i = 4; i > 0; i--)
        {
            if(board[i][5-i+1] != x)
            {
                x = 0;
                break;
            }
        }
        if(x != 0) return x;
    }
    if(board[4][1] != 0)
    {
        x = board[4][1];
        for(int i = 3; i >= 0; i--)
        {
            if(board[i][5-i] != x)
            {
                x = 0;
                break;
            }
        }
        if(x != 0) return x;
    }

    return 0;

}

int koniec(int** board)
{
    if(check_diagonal(board) == 1 || check_horizontal(board) == 1 || check_vertical(board) == 1)
    {
        return 1;
    }
    if(check_diagonal(board) == 2 || check_horizontal(board) == 2 || check_vertical(board) == 2)
    {
        return 2;
    }
    if((check_diagonal(board) == 1 || check_horizontal(board) == 1 || check_vertical(board) == 1) && (check_diagonal(board) == 2 || check_horizontal(board) == 2 || check_vertical(board) == 2))
    {
        return 3;
    }
    return 0;
}
