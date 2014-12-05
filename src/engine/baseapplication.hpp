#ifndef BASEAPPLICATION_HPP
#define BASEAPPLICATION_HPP

#include "common.hpp"

class BaseApplication
{
public:
   void run();

protected:
   virtual void init() = 0;
   virtual void clean() = 0;

   virtual void input() = 0;
   virtual void update() = 0;
   virtual void render() = 0;

   sf::RenderWindow * getWindow();
   void setWindow(sf::RenderWindow * window);

private:
   sf::RenderWindow * _window = nullptr;
};

#endif // BASEAPPLICATION_HPP
