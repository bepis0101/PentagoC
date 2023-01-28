#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <limits.h>
#include "player.h"
#include "bot.h"

typedef struct plansza
{
    int t[3][3]; 
}plansza;

void gameplay_multi();

void gameplay_single();

int menu();

void printw_arr(int** board, WINDOW* W);

void printw_borders(WINDOW* W);

plansza pusta(plansza x); // wypelnienie planszy zerami

int check(int** tab, int i, int j); // sprawdzenie czy pole jest wolne 

int** k_czarnych(int** tab, int i, int j);

int** k_bialych(int** tab, int i, int j);

plansza obrot_r(plansza x); // obrot w prawo 

plansza obrot_l(plansza x); // obrot w lewo

int** fill(int** tab, int val, int n);

int** rewrite(plansza P[], int** tab);

plansza* rewrite_b(plansza P[], int** tab);

void PRINT_arr(int** tab, int length, int height);

int koniec(int** board);

int** black_round(int** board, plansza P[]);

int** white_round(int** board, plansza P[]);

int check_vertical(int** board);

int check_horizontal(int** board);

int check_diagonal(int** board);

int** X_round_move(int** board, plansza bP[], WINDOW* W, player P);

int** turn_the_board(int** board, plansza bP[], WINDOW* W, player P);

int** O_round_move(int** board, plansza bP[], WINDOW* W, player P);

int random_generator(int min, int max);

int** create_matrix(int** board);
