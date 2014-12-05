#ifndef BASESCENE_HPP
#define BASESCENE_HPP

#include "common.hpp"

class BaseScene
{
public:
   void onEvent(const sf::Event & event);

   virtual void onInit();
   virtual void onReset();
   virtual void onClean();
   virtual void onUpdate();
   virtual void onRender(sf::RenderWindow * window);

protected:
   virtual void onKeyPressed(const sf::Event::KeyEvent & event);
   virtual void onKeyReleased(const sf::Event::KeyEvent & event);
   virtual void onMousePressed(const sf::Event::MouseButtonEvent & event);
   virtual void onMouseReleased(const sf::Event::MouseButtonEvent & event);
   virtual void onMouseMoved(const sf::Event::MouseMoveEvent & event);
};

#endif // BASESCENE_HPP
