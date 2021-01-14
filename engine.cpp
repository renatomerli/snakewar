#include "engine.h"
#include "globals.h"
#include <unistd.h>
#include "config.h"

#include <SDL2/SDL_events.h>

Engine::Engine(int Xres, int Yres)
{
    resolution.set(Xres, Yres);
}

void Engine::init()
{
    reset_apple();
}

int Engine::get_num_snakes() 
{
     return snakes_list.size(); 
}

bool Engine::attach(SnakeBase *_snake) 
{
    _snake->init(get_randon_dot(), UP, ++num_snakes);
    snakes_list.push_back(_snake);
}

list<SnakeBase*> Engine::get_snakes()
{
    return snakes_list;
}

void Engine::reset_apple() 
{ 
    Cartesian _last_apple = apple;
    while (_last_apple == apple || have_dot(apple))  apple = get_randon_dot();
    apple_count++;
    view->print_apple( apple);
}
Cartesian Engine::get_randon_dot()
{
    while(true)
    {
        Cartesian tmp_dot(rand() % resolution.getX(), rand() % resolution.getY() );
        if (! have_dot(tmp_dot)) return tmp_dot;
    }
}
bool Engine::validate_step(Direction _dot)
{
    if ( have_dot( _dot)) { /* cout << "falhou em have_dot" << endl; */ return false; }
    if ( ! check_border(  _dot )) { /* cout << "falhou em check_border" << endl; */ return false; }
    return true;    
}
bool Engine::have_dot (Cartesian _dot)
{
    for (SnakeBase  *_snake : snakes_list)
    {
        if (!_snake->is_alive()) continue;
        for (Cartesian _snakeDot : _snake->get_body())
        {
            if (_snakeDot == _dot) { /* cout << "Colapsed with snake " << _snake->get_name() << endl ;  */ return true; }
        }
    }
    return false;
}
bool Engine::check_border (Cartesian _input)
{
    if (_input.getX() < 0 || _input.getX() > resolution.getX() ) return false;
    if (_input.getY() < 0 || _input.getY() > resolution.getY() ) return false;
    return true;
}

void Engine::move(SnakeBase* _snake, Spin _spin )
{
    
    Cartesian _target = _snake->get_head() + _spin;
    _snake->get_body().push_front(_target);
    view->print_dot(_target,  _snake->get_num());

    
    if (_target != apple ) 
    {
        view->delete_dot(_snake->get_body().back());
        _snake->get_body().pop_back();
    }
    else
    {
        reset_apple(); 
    }
 
}

void Engine::kill(SnakeBase* _snake)
{
    for (auto _dot : _snake->get_body())
    {
        view->delete_dot(_dot);
    }
    _snake->die();
    num_snakes--;

}

void Engine::run()
{   

    while (++steps < 10000)
    {
        while (AppConfig::get_instance()->get_stoped()) {  usleep(10000); view->refresh(); view->get_command();}
        for (SnakeBase *tmp_snake : snakes_list)
        { 
            if (!tmp_snake->is_alive() ) { continue; }

            Spin tspin = tmp_snake->play(Cartesian(resolution), Cartesian(apple), list<SnakeBase*>  (snakes_list) );

            if (tspin == NONE) { kill(tmp_snake); continue;}

            if ( ! validate_step (tmp_snake->get_head() + tspin)) 
            { 

                kill(tmp_snake);
                continue;
            }

            move(tmp_snake, tspin);
        }
        if (! get_num_snakes()) {  continue ;}
        view->get_command();
        view->refresh();
        usleep(AppConfig::get_instance()->get_delay()  );

SDL_Event evt;
{
  SDL_PollEvent(&evt);
  if(evt.type == SDL_QUIT)
    exit(1);
}
    }

}
