#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "engine/baseapplication.hpp"

class Game;
class MainMenu;

class Application : public BaseApplication
{
private:
   void init();
   void clean();

   void input();
   void update();
   void render();

private:
   Game * _game = nullptr;
   MainMenu * _menu = nullptr;
};

#endif // APPLICATION_HPP
