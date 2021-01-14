#pragma once

class ViewBase
{
    public:
    ViewBase() {};
//    ~ViewBase(){};    
    virtual void print_dot(Cartesian pos, int color) = 0;
    virtual void delete_dot(Cartesian pos) = 0;
    virtual void print_apple(Cartesian pos) = 0;
    virtual void refresh() = 0;
    virtual void get_command() = 0;
};

