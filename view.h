#pragma once

#include <ncurses.h>
#include <iostream>

#include "cartesian.h"
//#include "config.h"


#define COLOR_BKG COLOR_BLACK

class Board
{
    private:
    WINDOW *border;
    WINDOW *viewer;
    int Xres, Yres;

    public: 
    ~Board() {delwin(viewer); delwin(border); endwin();}
    Board ()
    {

        stdscr = initscr();
        nodelay(stdscr,TRUE);

        start_color();
        curs_set(0);
        noecho();
        cbreak();

        init_pair(0, COLOR_WHITE, COLOR_BKG);
        init_pair(1, COLOR_BLUE, COLOR_BKG);
        init_pair(2, COLOR_RED, COLOR_BKG);
        init_pair(3, COLOR_GREEN, COLOR_BKG);
        init_pair(4, COLOR_YELLOW, COLOR_BKG);
        init_pair(5, COLOR_MAGENTA, COLOR_BKG);
        init_pair(6, COLOR_CYAN, COLOR_BKG);
        init_pair(77, COLOR_WHITE, COLOR_BKG);
    }

    Cartesian get_resolution()
    {

        int x, y;
        getmaxyx (stdscr, y, x);
        return Cartesian(x,y);
    }

    void init(Cartesian _res)
    {
        init (_res.getX(), _res.getY());
    }

    void init(int _Xres, int _Yres)
    {
        Xres = _Xres;
        Yres = _Yres;
        
        border = newwin(Yres, Xres, 0,0);
        wattron(border, COLOR_PAIR(2));
        box(border, 0,0 );

        viewer = newwin( Yres-2, Xres-2, 1,1);

        wrefresh(viewer);
    
    }

    void process_command (int _command)
    {

        switch (_command)
        {
        case 66:
        case KEY_DOWN:
            AppConfig::get_instance()->increase_delay();
            break;

        case 65:
        case KEY_UP:
            AppConfig::get_instance()->decrease_delay();           
            break;

        case 51:
            AppConfig::get_instance()->increase_delayx();           
            break;
        case 57:
            AppConfig::get_instance()->decrease_delayx();           
            break;

        case 'q':
            endwin();
            exit(1);
            break;

        case 32:
            AppConfig::get_instance()->switch_stoped();           
            break;

        default:
            break;
        }

    }

    void get_command()
    {
    int command = 0;
    
    if ( (command = getch()) != ERR) 
    {
        if (command == 27 ) { getch(); process_command(getch()); }
        else if (command != ERR )process_command (command);
    }
    }

    void printxy(int X, int Y, char ch, int color_code)
    {
        wattron(viewer, COLOR_PAIR(color_code));
        mvwaddch  ( viewer, Y, X, ch);
    }

    void printxy (Cartesian _dot, char ch, int color_code)
    {
        printxy (_dot.getX(), _dot.getY(), ch, color_code);
    }

    void print (string input)
    {
        wprintw (viewer,  input.c_str());
    }

    void refresh()
    {
    wrefresh(border);
    wrefresh(viewer);
    }
    
};