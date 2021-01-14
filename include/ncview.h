#pragma once

#include <ncurses.h>
#include <iostream>

#include "cartesian.h"
#include "viewbase.h"

#define COLOR_BKG COLOR_BLACK



class NCView : public ViewBase
{
    private:
    WINDOW *border;
    WINDOW *viewer;

    public: 
    ~NCView() ;
    NCView () ;
    Cartesian get_resolution();
    void init(Cartesian _res);

    void process_command (int _command);
    void get_command();
    void print_apple(Cartesian pos);
    void delete_dot(Cartesian pos);

    void print_dot (Cartesian pos, int color);
    void printyx (Cartesian pos, char ch);

    void print (string input);
    void refresh();
    
};