#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "engine/basescene.hpp"

class MainMenu : public BaseScene
{
public:
   void onInit();
   void onRender(sf::RenderWindow * window);

   void onKeyPressed(const sf::Event::KeyEvent & event);
   void onMousePressed(const sf::Event::MouseButtonEvent & event);

private:
   std::vector<sf::Text>  _buttons;
   std::vector<std::pair<sf::IntRect, std::function<void ()> > > _callbacks;
};

#endif // MAINMENU_HPP
