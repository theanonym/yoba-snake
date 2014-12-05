#ifndef GAME_HPP
#define GAME_HPP

#include "engine/basescene.hpp"

class World;

class Game : public BaseScene
{
public:
   void onInit();
   void onUpdate();
   void onRender(sf::RenderWindow * window);

private:
   void reset();

   static sf::Vector2f cellToCoords(const sf::Vector2i & pos);

   void onKeyPressed(const sf::Event::KeyEvent & event);

private:
   World * _world = nullptr;
};

#endif // GAME_HPP
