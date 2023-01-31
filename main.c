#include "function.h"

int main()
{
    initscr();
    start_color();
    int menu_choice = menu();
    if(menu_choice == 0)
    {
        gameplay_single();
    }
    else if(menu_choice == 1)
    {
        gameplay_multi();
    }
    else
    {
        endwin();
        exit(0);
    }
    getch();
    endwin();
}

