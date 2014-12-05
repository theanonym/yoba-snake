#include "basescene.hpp"

void BaseScene::onEvent(const sf::Event & event)
{
   switch(event.type)
   {
      case sf::Event::KeyPressed:          onKeyPressed(event.key); break;
      case sf::Event::KeyReleased:         onKeyReleased(event.key); break;
      case sf::Event::MouseButtonPressed:  onMousePressed(event.mouseButton); break;
      case sf::Event::MouseButtonReleased: onMouseReleased(event.mouseButton);  break;
      case sf::Event::MouseMoved:          onMouseMoved(event.mouseMove); break;
      default: break;
   }
}

void BaseScene::onInit()
{
}

void BaseScene::onReset()
{
}

void BaseScene::onClean()
{
}

void BaseScene::onUpdate()
{
}

void BaseScene::onRender(sf::RenderWindow *)
{
}

void BaseScene::onKeyPressed(const sf::Event::KeyEvent &)
{
}

void BaseScene::onKeyReleased(const sf::Event::KeyEvent & )
{
}

void BaseScene::onMousePressed(const sf::Event::MouseButtonEvent &)
{
}

void BaseScene::onMouseReleased(const sf::Event::MouseButtonEvent &)
{
}

void BaseScene::onMouseMoved(const sf::Event::MouseMoveEvent &)
{
}
