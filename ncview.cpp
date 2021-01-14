#include "cartesian.h"
#include "viewbase.h"
#include "ncview.h"
#include <ncurses.h>

#include "config.h"

NCView::~NCView()  {delwin(viewer); delwin(border); endwin();}

NCView::NCView () 
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

Cartesian NCView::get_resolution()
    {

        int x, y;
        getmaxyx (stdscr, y, x);
        return Cartesian(x,y);
    }

void NCView::init(Cartesian res)
    {
        
        border = newwin(res.getY(), res.getX(), 0,0);
        wattron(border, COLOR_PAIR(2));
        box(border, 0,0 );

        viewer = newwin( res.getY()-2, res.getX()-2, 1,1);

        wrefresh(viewer);
    
    }


void NCView::print_apple(Cartesian pos)
{

        wattron(viewer, COLOR_PAIR(4));
        printyx (pos, 'G');


}
void NCView::delete_dot(Cartesian pos)
{
        wattron(viewer, COLOR_PAIR(0));
        printyx (pos, ' ');


}

void NCView::print_dot (Cartesian pos, int color)
    {
       wattron(viewer, COLOR_PAIR(color));
       printyx (pos, '#');
    }



void NCView::printyx (Cartesian pos, char ch)
    {
        mvwaddch  ( viewer, pos.getY(), pos.getX(), ch);

    }
void NCView::print (string input)
    {
        wprintw (viewer,  input.c_str());
    }

void NCView::refresh()
    {
    wrefresh(border);
    wrefresh(viewer);
    }

void NCView::get_command()
    {
    int command = 0;
    
    if ( (command = getch()) != ERR) 
    {
        if (command == 27 ) { getch(); process_command(getch()); }
        else if (command != ERR )process_command (command);
    }
    }

void NCView::process_command (int _command)
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

