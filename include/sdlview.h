#pragma once

#include "viewbase.h"
#include "cartesian.h"

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h> 

class SdlView : public ViewBase
{

    public:
    SdlView();

    Cartesian resolution;
    int size;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture* tex;
    SDL_Rect* rect;

    void init(Cartesian res, int _size);
    const SDL_Rect* get_target (Cartesian pos);

    void print_dot(Cartesian pos, int color_code);
    void print_apple(Cartesian pos);
    void delete_dot(Cartesian pos);

    void refresh();
    void get_command();



};