#include "world.hpp"
#include "state.hpp"
#include "engine/random.hpp"

World::World(int width, int height)
   : _worldSize(width, height)
{
   _updateTime = 0.25f;

   _snake = new Snake;

   Segment * a = new Segment();
   a->pos = sf::Vector2i(10, 10);
   _snake->addSegment(a);

   for(int i = 0; i < 1; i++)
   {
      Segment * b = new Segment();
      b->pos = sf::Vector2i(10, 11 + i);
      _snake->addSegment(b);
   }


   createFood();
}

void World::clear()
{
   delete _snake;
   _snake = new Snake();
}

void World::update()
{
   if(_snake->getDir() == Snake::None)
      return;

   if(_timer.getElapsedTime().asSeconds() >= _updateTime)
   {
      sf::Vector2i tailPos = getSnake()->getTail()->pos;

      bool gameOver = false;

      sf::Vector2i nextHeadPos = getSnake()->getNextPos();

      std::vector<sf::Vector2i> forbiddenCells(getForbiddenCells());
      for(const sf::Vector2i & cell : forbiddenCells)
         if(nextHeadPos == cell)
            gameOver = true;

      if(gameOver)
      {
         State::get().game.isGameOver = true;
         State::get().game.scores = (_snake->getSize() - 2);
         return;
      }

      _snake->update();


      if(_snake->getHead()->pos == _foodPos)
      {


         Segment * newTail = new Segment;
         newTail->pos = tailPos;
         _snake->addSegment(newTail);

         createFood();

         _updateTime -= 0.003;
         if(_updateTime < 0.05)
            _updateTime = 0.05;
      }


      _timer.restart();
   }

   _ticks++;
}

Snake * World::getSnake() const
{
   assert(_snake);
   return _snake;
}

void World::createFood()
{

   std::vector<sf::Vector2i> forbiddenCells(getForbiddenCells());

   // А мне норм
   bool success = false;
   while(!success)
   {
      sf::Vector2i foodPos(Random::get().getInt(0, _worldSize.x - 1),
                           Random::get().getInt(0, _worldSize.y - 1));
      success = true;
      for(const sf::Vector2i & forbiddenCell : forbiddenCells)
         if(foodPos == forbiddenCell)
            success = false;

      _foodPos = foodPos;
   }
}

const sf::Vector2i & World::getFoodPos() const
{
   return _foodPos;
}

std::vector<sf::Vector2i> World::getForbiddenCells() const
{
   std::vector<sf::Vector2i> forbiddenCells;
   Segment * node = _snake->getHead();
   do {
      forbiddenCells.push_back(node->pos);
      if(node->hasNext())
         node = node->next;
   } while(node->hasNext());
   return forbiddenCells;
}

