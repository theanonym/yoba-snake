#include "game.hpp"
#include "state.hpp"
#include "world.hpp"
#include "engine/resources.hpp"

void Game::onInit()
{

}

void Game::reset()
{
   State::get().game.isStarted = true;
   State::get().game.isPaused = false;
   State::get().game.isGameOver = false;
   _world = new World(21, 21);
}

void Game::onUpdate()
{
   if(!State::get().game.isStarted)
      reset();

   if(!State::get().game.isPaused && !State::get().game.isGameOver)
      _world->update();
}

void Game::onRender(sf::RenderWindow * window)
{
   const sf::Texture * bgtxt = Resources::get().getTexture("background");
   const sf::Texture * headtxt = Resources::get().getTexture("head");
   const sf::Texture * lstxt = Resources::get().getTexture("segment_linear");
   const sf::Texture * astxt = Resources::get().getTexture("segment_angular");
   const sf::Texture * tstxt = Resources::get().getTexture("segment_tail");
   const sf::Texture * ftxt = Resources::get().getTexture("food");

   window->clear(sf::Color(255, 226, 148));
   sf::Sprite background(*bgtxt);
   background.setPosition(0, 0);
   window->draw(background);

   Snake * snake = _world->getSnake();

   Segment * node = snake->getHead();
   while(true)
   {
      sf::Sprite sprite;
      sprite.setOrigin(25.f / 2.f, 25.f / 2.f);
      sprite.setPosition(cellToCoords(node->pos) + sf::Vector2f(25.f / 2.f, 25.f / 2.f));

      if(!node->hasPrevious())
      {
         sprite.setTexture(*headtxt);
         if(node->hasLeft())
            sprite.setRotation(0);
         else if(node->hasUpper())
            sprite.setRotation(90);
         else if(node->hasRight())
            sprite.setRotation(180);
         else
            sprite.setRotation(270);
      }
      else if(node->hasLeft())
      {
         if(node->hasRight())
         {
            sprite.setTexture(*lstxt);
         }
         else if(node->hasUpper())
         {
            sprite.setTexture(*astxt);
         }
         else if(node->hasLower())
         {
            sprite.setTexture(*astxt);
            sprite.setRotation(270);
         }
         else
         {
            sprite.setTexture(*tstxt);
         }
      }
      else if(node->hasRight())
      {
         if(node->hasUpper())
         {
            sprite.setTexture(*astxt);
            sprite.setRotation(90);
         }
         else if(node->hasLower())
         {
            sprite.setTexture(*astxt);
            sprite.setRotation(180);
         }
         else
         {
            sprite.setTexture(*tstxt);
            sprite.setRotation(180);
         }
      }
      else if(node->hasUpper())
      {
         if(node->hasLower())
         {
            sprite.setTexture(*lstxt);
            sprite.setRotation(90);
         }
         else
         {
            sprite.setTexture(*tstxt);
            sprite.setRotation(90);
         }
      }
      else if(node->hasLower())
      {
         sprite.setTexture(*tstxt);
         sprite.setRotation(270);
      }
      else
      {

         assert(0);
      }

      window->draw(sprite);

      if(node->hasNext())
         node = node->next;
      else
         break;
   }

   sf::Sprite food(*ftxt);
   food.setPosition(cellToCoords(_world->getFoodPos()));
   window->draw(food);

   if(State::get().game.isPaused)
   {
      sf::Text pause(L"Пауза", *Resources::get().getFont("comic"), 60);
      pause.setColor(sf::Color::Green);
      pause.setPosition(window->getSize().x / 2 - pause.getGlobalBounds().width  / 2,
                        window->getSize().y / 2 - pause.getGlobalBounds().height / 1.5);
      window->draw(pause);


      sf::RectangleShape cover(sf::Vector2f(window->getSize()));
      cover.setFillColor(sf::Color(0, 0, 0, 50));
      window->draw(cover);
   }

   if(State::get().game.isGameOver)
   {


      sf::Text text(L"GAME OVER", *Resources::get().getFont("comic"), 60);
      text.setStyle(sf::Text::Bold);
      text.setColor(sf::Color::Red);
      text.setPosition(window->getSize().x / 2 - text.getGlobalBounds().width  / 2,
                       window->getSize().y / 2 - text.getGlobalBounds().height / 1.5);
      window->draw(text);

      std::stringstream ss;
      ss << State::get().game.scores;
      sf::Text scores(ss.str(), *Resources::get().getFont("comic"), 70);
      scores.setStyle(sf::Text::Bold);
      scores.setColor(sf::Color::Green);
      scores.setPosition(window->getSize().x / 2 - scores.getGlobalBounds().width  / 2,
                         text.getGlobalBounds().top + text.getGlobalBounds().height);
      window->draw(scores);

      sf::RectangleShape cover(sf::Vector2f(window->getSize()));
      cover.setFillColor(sf::Color(0, 0, 0, 50));
      window->draw(cover);
   }
}

sf::Vector2f Game::cellToCoords(const sf::Vector2i & pos)
{
   return sf::Vector2f(pos.x * 25, pos.y * 25);
}

void Game::onKeyPressed(const sf::Event::KeyEvent & event)
{
   Snake   * snake = _world->getSnake();
   Segment * head  = snake->getHead();

   switch(event.code)
   {
      case sf::Keyboard::Escape:
         if(State::get().game.isGameOver)
            State::get().game.isStarted = false;
         else
            State::get().mode = State::MainMenu;
         break;

      case sf::Keyboard::Left:
         if(!head->hasLeft()) snake->setDir(Snake::Left);
         break;

      case sf::Keyboard::Right:
         if(!head->hasRight()) snake->setDir(Snake::Right);
         break;

      case sf::Keyboard::Up:
         if(!head->hasUpper()) snake->setDir(Snake::Up);
         break;

      case sf::Keyboard::Down:
         if(!head->hasLower()) snake->setDir(Snake::Down);
         break;

      case sf::Keyboard::Space:
         if(!State::get().game.isGameOver)
            State::get().game.isPaused = !State::get().game.isPaused;
         break;

      case sf::Keyboard::C:
         snake->addSegment(new Segment );
         break;

      default:
         break;
   }
}
