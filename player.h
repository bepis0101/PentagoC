#include <ncurses.h>
#include <stdio.h>


typedef struct player
{
    WINDOW *W;
    char c;
    int x;
    int y;

}player;

player create(player P, WINDOW* W);

player move_up(player P);

player move_down(player P);

player move_left(player P);

player move_right(player P);

player move_board_u(player P);

player move_board_d(player P);

player move_board_r(player P);

player move_board_l(player P);