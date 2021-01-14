#include "cartesian.h"
#include "sdlview.h"
#include "rgb.h"

SdlView::SdlView(){};

void SdlView::init(Cartesian res, int _size=1)
{
    resolution.setX(res.getX());
    resolution.setY(res.getY());
    size = _size;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Snake War", 
                                SDL_WINDOWPOS_CENTERED, 
                                SDL_WINDOWPOS_CENTERED, 
                                resolution.getX() * size, resolution.getY() * size, 0); 

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    rect = new SDL_Rect;
}

const SDL_Rect* SdlView::get_target (Cartesian pos)
{
    rect->x = pos.getX() * size;
    rect->y = pos.getY() * size;
    rect->w = size;
    rect->h = size;
    return rect;
}

void SdlView::print_apple(Cartesian pos)
{
    SDL_SetRenderDrawColor( renderer, 255, 215, 0, 255 );
    SDL_RenderFillRect( renderer, get_target(pos) );
}

void SdlView::delete_dot(Cartesian pos)
{
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderFillRect( renderer, get_target(pos) );
}

void SdlView::print_dot(Cartesian pos, int color_code)
{
    SDL_SetRenderDrawColor( renderer, COLORS[color_code % COLORS.size()].a, COLORS[color_code % COLORS.size()].b, COLORS[color_code % COLORS.size()].c, 255 );
    SDL_RenderFillRect( renderer, get_target(pos) );
}

void SdlView::refresh()
{      
    SDL_RenderPresent(renderer); 
}
    
void SdlView::get_command(){};

