#pragma once

#define MAXSNAKES 6

class AppConfig
{
private:
   AppConfig(){};

   bool stoped=false;
   int delay=100000;

public:
   static AppConfig* get_instance()
   {
    static AppConfig *INSTANCE = 0;
    if (!INSTANCE)
    INSTANCE = new AppConfig();
    return INSTANCE;
    }

    int get_delay() { return delay;} 
    void increase_delay() { delay += 10000; delay = delay > 100000 ? 100000 : delay;}
    void decrease_delay() { delay -= 10000; delay = delay < 1000 ? 1000 : delay;}
    void increase_delayx() { delay *= 2; delay = delay > 100000 ? 100000 : delay;}
    void decrease_delayx() { delay /= 2; delay = delay < 1000 ? 1000 : delay;}

    bool get_stoped() { return stoped ;}
    void switch_stoped() { stoped = !stoped;}


};



class AppState
{
public:
private:
   AppState(){};

public:
   static AppState* get_instance()
   {
    static AppState *INSTANCE = 0;
    if (!INSTANCE)
    INSTANCE = new AppState();
    return INSTANCE;
    }
};

