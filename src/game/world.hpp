#ifndef WORLD_HPP
#define WORLD_HPP

#include "engine/common.hpp"
#include "snake.hpp"

class World
{
public:

public:
   World(int width, int height);

   void clear();

   void update();
   void draw(sf::RenderWindow & window);

   Snake * getSnake() const;

   void createFood();
   const sf::Vector2i & getFoodPos() const;

   std::vector<sf::Vector2i> getForbiddenCells() const;


private:
   sf::Vector2i _worldSize;

   Snake * _snake = nullptr;

   unsigned _ticks = 0;
   sf::Clock _timer;
   float _updateTime;

   sf::Vector2i _foodPos;


};

#endif // WORLD_HPP
