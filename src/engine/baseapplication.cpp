#include "baseapplication.hpp"

void BaseApplication::run()
{
   init();

   while(getWindow()->isOpen())
   {
      input();
      update();
      render();
   }

   clean();
}

sf::RenderWindow * BaseApplication::getWindow()
{
   assert(_window);
   return _window;
}

void BaseApplication::setWindow(sf::RenderWindow * window)
{
   assert(window);
   _window = window;
}
