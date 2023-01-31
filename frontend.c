#include "function.h"
// #include "player.h"

int menu()
{
    noecho();
    char options[3][15] = {"Singleplayer", "Multiplayer", "EXIT"};
    int Xmax, Ymax;
    getmaxyx(stdscr, Ymax, Xmax);
    WINDOW * menuwin = newwin(5, 20, (Ymax/2)-3, (Xmax/2)-10);
    keypad(menuwin, 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    int choice;
    int highlight = 0;
    while(1)
    {
        for(int i = 0; i < 3; i++)
        {
            if(i == highlight) wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, options[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);
        if(choice == KEY_UP)
        {
            highlight--;
            if(highlight == -1) highlight = 0;
        }
        if(choice == KEY_DOWN)
        {
            highlight++;
            if(highlight == 3) highlight = 2;
        }
        if(choice == 10)
        {
            wclear(menuwin);
            wrefresh(menuwin);
            return highlight;
        }
    }
}

void printw_borders(WINDOW* W, int which_round)
{
    box(W, 0, 0);
    for(int i = 1; i < getmaxx(W)-1; i++)
    {
        mvwprintw(W, 10, i, "-");
    }
    for(int i = 1; i < getmaxy(W)-1; i++)
    {        
        mvwprintw(W, i , 20, "|");
    }
    mvwprintw(W, 10, 20, "+");
    wrefresh(W);
    if(which_round <= 3)
    {
        mvprintw(22, (getmaxx(stdscr)/2)-25, "Po planszy poruszaj sie strzalkami na klawiaturze");
        mvprintw(23, (getmaxx(stdscr)/2)-14, "Wybory zatwierdzaj Enterem.");
        refresh();
    }
}
void printw_arr(int** board, WINDOW* W)
{
    int x = 5, y = 2;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(board[j][i] == 0) mvwprintw(W, y, x, "%c", '.');
            if(board[j][i] == 1) mvwprintw(W, y, x, "%c", 'X');
            if(board[j][i] == 2) mvwprintw(W, y, x, "%c", 'O');
            x += 6;
        }
        x = 5;
        y += 3;
    }
    
    wrefresh(W);
    refresh();
}
player create(player P, WINDOW* win)
{
    P.W = win;
    P.x = 5;
    P.y = 2;
    return P;
}

player move_up(player P)
{
    P.y -= 3;
    if(P.y < 2)
    {
        P.y = 2;
    }
    return P;
}
player move_down(player P)
{
    P.y += 3;
    if(P.y > 17)
    {
        P.y = 17;
    }
    return P;
}
player move_right(player P)
{
    P.x += 6;
    if(P.x > 35)
    {
        P.x = 35;
    }
    return P;
}
player move_left(player P)
{
    P.x -= 6;
    if(P.x < 5)
    {
        P.x = 5;
    }
    return P;
}
int** X_round_move(int** board, plansza bP[], WINDOW* W, player P)
{
    while(1)
    {
        wmove(W, P.y, P.x);
        wattron(W, A_REVERSE);
        wrefresh(W);
        wattroff(W, A_REVERSE);
        int cc = wgetch(W);
        int X = (P.x)/6, Y = (P.y)/3;
        if(cc == '\n' && check(board, X, Y))
        {
            board = k_czarnych(board, X, Y);
            break;
        }
        if(cc == KEY_UP)
        {
            P = move_up(P);
        }
        if(cc == KEY_DOWN)
        {
            P = move_down(P);
        }
        if(cc == KEY_LEFT)
        {
            P = move_left(P);
        }
        if(cc == KEY_RIGHT)
        {
            P = move_right(P);
        }
    }
    wrefresh(W);
    return board;
    
}
int** O_round_move(int** board, plansza bP[], WINDOW* W, player P)
{
    while(1)
    {
        wmove(W, P.y, P.x);
        wattron(W, A_REVERSE);
        wrefresh(W);
        wattroff(W, A_REVERSE);
        int cc = wgetch(W);
        int X = (P.x)/6, Y = (P.y)/3;
        if(cc == '\n' && check(board, X, Y))
        {
            board = k_bialych(board, X, Y);
            break;
        }
        if(cc == KEY_UP)
        {
            P = move_up(P);
        }
        if(cc == KEY_DOWN)
        {
            P = move_down(P);
        }
        if(cc == KEY_LEFT)
        {
            P = move_left(P);
        }
        if(cc == KEY_RIGHT)
        {
            P = move_right(P);
        }
    }
    wrefresh(W);
    return board;
}
player move_board_u(player P)
{
    P.y = 5;
    return P;
}
player move_board_d(player P)
{
    P.y = 14;
    return P;
}
player move_board_l(player P)
{
    P.x = 11;
    return P;
}
player move_board_r(player P)
{
    P.x = 29;
    return P;
}
int** turn_the_board(int** board, plansza bP[], WINDOW* W, player P)
{
    bP = rewrite_b(bP, board);
    P.x = 11;
    P.y = 5;
    while(1)
    {
        wmove(W, P.y, P.x);
        wrefresh(W);
        wattron(W, A_REVERSE);
        int cc = wgetch(W);
        wrefresh(W);
        wattroff(W, A_REVERSE);
        if(cc == '\n')
        {
            cc = wgetch(W);
            while(!(cc == KEY_LEFT || cc == KEY_RIGHT)) cc = wgetch(W);
            if(cc == KEY_LEFT)
            {
                if(P.x > 11)
                {
                    if(P.y > 5)
                    {
                        bP[3] = obrot_l(bP[3]);
                    }
                    else
                    {
                        bP[1] = obrot_l(bP[1]);
                    }
                }
                else
                {
                    if(P.y > 5)
                    {
                        bP[2] = obrot_l(bP[2]);
                    }
                    else
                    {
                        bP[0] = obrot_l(bP[0]);
                    }
                }
            }
            if(cc == KEY_RIGHT)
            {
                if(P.x > 11)
                {
                    if(P.y > 5)
                    {
                        bP[3] = obrot_r(bP[3]);
                    }
                    else
                    {
                        bP[1] = obrot_r(bP[1]);
                    }
                }
                else
                {
                    if(P.y > 5)
                    {
                        bP[2] = obrot_r(bP[2]);
                    }
                    else
                    {
                        bP[0] = obrot_r(bP[0]);
                    }
                }
            }
            board = rewrite(bP, board);
            break;
        }
        if(cc == KEY_UP)
        {
            P = move_board_u(P);
            continue;
        }
        if(cc == KEY_DOWN)
        {
            P = move_board_d(P);
            continue;
        }
        if(cc == KEY_LEFT)
        {
            P = move_board_l(P);
            continue;
        }
        if(cc == KEY_RIGHT)
        {
            P = move_board_r(P);
            continue;
        }
    }
    return board;
}
void gameplay_multi()
{
    int** board = (int**)malloc(6*sizeof(int*));
    for(int i = 0; i < 6; i++) board[i] = (int*)malloc(6*sizeof(int));
    plansza board_s[4];
    for(int i = 0; i < 4; i++)
    {
        pusta(board_s[i]);
    }
    board = fill(board, 0, 6);
    int Xmax, Ymax; getmaxyx(stdscr, Ymax, Xmax);
    WINDOW* boardd = newwin(20, 40, (Ymax/2)-10, (Xmax/2)-20);
    keypad(boardd, 1);
    int which_round = 1;
    printw_borders(boardd, which_round);
    printw_arr(board, boardd);
    refresh();
    player P;
    P = create(P, boardd);
    while(1)
    {
        if(koniec(board) == 0)
        {
            board = X_round_move(board, board_s, boardd, P);
            werase(boardd);
            wrefresh(boardd);
            printw_borders(boardd, which_round);
            printw_arr(board, boardd);
            wrefresh(boardd);
            refresh();
            board = turn_the_board(board, board_s, boardd, P);
            werase(boardd);
            wrefresh(boardd);
            printw_borders(boardd, which_round);
            printw_arr(board, boardd);
            wrefresh(boardd);
            refresh();
        }

        else
        {
            if(koniec(board) == 3)
            {
                // remis
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-3, "REMIS!");
                refresh();
                break;
            }
            if(koniec(board) == 2)
            {
                // zwyciestwo O
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-6, "ZWYCIESTWO O!");
                refresh();
                break;
            }
            if(koniec(board) == 1)
            {
                // zwyciestwo X
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-6, "ZWYCIESTWO X!");
                refresh();
                break;
            }
        }
        if(koniec(board) == 0)
        {
            board = O_round_move(board, board_s, boardd, P);
            werase(boardd);
            wrefresh(boardd);
            printw_borders(boardd, which_round);
            printw_arr(board, boardd);
            wrefresh(boardd);
            refresh();
            board = turn_the_board(board, board_s, boardd, P);
            werase(boardd);
            wrefresh(boardd);
            printw_borders(boardd, which_round);
            printw_arr(board, boardd);
            wrefresh(boardd);
            refresh();
            which_round++;
        }
        else
        {
            if(koniec(board) == 3)
            {
                // remis
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-3, "REMIS!");
                refresh();
                break;
            }
            if(koniec(board) == 2)
            {
                // zwyciestwo O
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-6, "ZWYCIESTWO O!");
                refresh();
                break;
            }
            if(koniec(board) == 1)
            {
                // zwyciestwo X
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-6, "ZWYCIESTWO X!");
                refresh();
                break;
            }
        }
    }
}
int random_generator(int min, int max)
{
    return ((rand()%max)+min);
}

void gameplay_single()
{
    int** board = (int**)malloc(6*sizeof(int*));
    for(int i = 0; i < 6; i++) board[i] = (int*)malloc(6*sizeof(int));
    plansza* board_s = (plansza*)malloc(4*sizeof(plansza));
    for(int i = 0; i < 4; i++)
    {
        pusta(board_s[i]);
    }
    board = fill(board, 0, 6);
    int Xmax, Ymax; getmaxyx(stdscr, Ymax, Xmax);
    WINDOW* boardd = newwin(20, 40, (Ymax/2)-10, (Xmax/2)-20);
    keypad(boardd, 1);
    int which_round = 1;
    printw_borders(boardd, which_round);
    printw_arr(board, boardd);
    refresh();
    player P;
    P = create(P, boardd);
    while(1)
    {
        if(koniec(board) == 0)
        {
            board = X_round_move(board, board_s, boardd, P);
            werase(boardd);
            wrefresh(boardd);
            printw_borders(boardd, which_round);
            printw_arr(board, boardd);
            wrefresh(boardd);
            refresh();
            board = turn_the_board(board, board_s, boardd, P);
            werase(boardd);
            wrefresh(boardd);
            printw_borders(boardd, which_round);
            printw_arr(board, boardd);
            wrefresh(boardd);
            refresh();
        }

        else
        {
            if(koniec(board) == 3)
            {
                // remis
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-3, "REMIS!");
                refresh();
                break;
            }
            if(koniec(board) == 2)
            {
                // zwyciestwo O
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-6, "ZWYCIESTWO O!");
                refresh();
                break;
            }
            if(koniec(board) == 1)
            {
                // zwyciestwo X
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-6, "ZWYCIESTWO X!");
                refresh();
                break;
            }
        }
        if(koniec(board) == 0)
        {
            int x, y;
            // if(which_round <= 4)
            // {
            x = random_generator(0, 5); 
            y = random_generator(0, 5);
            while(!check(board, x, y))
            {
                x = random_generator(0, 5);
                y = random_generator(0, 5);
            }
            // }
            /*else
            {
                pair p; p = best_move(board);
                x = p.x;
                y = p.y;
            }*/
            board = k_bialych(board, x, y);
            werase(boardd);
            wrefresh(boardd);
            printw_borders(boardd, which_round);
            printw_arr(board, boardd);
            wrefresh(boardd);
            refresh();
            board_s = rewrite_b(board_s, board);
            int choice = random_generator(0, 3);
            int side = random_generator(0, 1);
            if(side == 0)
            {
                board_s[choice] = obrot_l(board_s[choice]);
            }
            else
            {
                board_s[choice] = obrot_r(board_s[choice]);
            }
            board = rewrite(board_s, board);
            werase(boardd);
            wrefresh(boardd);
            printw_borders(boardd, which_round);
            printw_arr(board, boardd);
            wrefresh(boardd);
            refresh();
            which_round++;
        }
        else
        {
            if(koniec(board) == 3)
            {
                // remis
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-3, "REMIS!");
                refresh();
                break;
            }
            if(koniec(board) == 2)
            {
                // zwyciestwo O
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-6, "ZWYCIESTWO O!");
                refresh();
                break;
            }
            if(koniec(board) == 1)
            {
                // zwyciestwo X
                werase(boardd);
                wrefresh(boardd);
                erase();
                refresh();
                mvprintw(Ymax/2, (Xmax/2)-6, "ZWYCIESTWO X!");
                refresh();
                break;
            }
        }
    }
}