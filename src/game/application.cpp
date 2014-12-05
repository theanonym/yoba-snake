#include "application.hpp"
#include "game.hpp"
#include "mainmenu.hpp"
#include "state.hpp"
#include "engine/resources.hpp"

void Application::init()
{
   Resources::get().loadTexture("icon", "res/png/icon.png");

   Resources::get().loadTexture("background",      "res/png/background.png");
   Resources::get().loadTexture("head",            "res/png/head.png");
   Resources::get().loadTexture("segment_linear",  "res/png/segment_linear.png");
   Resources::get().loadTexture("segment_angular", "res/png/segment_angular.png");
   Resources::get().loadTexture("segment_tail",    "res/png/segment_tail.png");
   Resources::get().loadTexture("food",            "res/png/food.png");

   Resources::get().loadFont("comic", "res/ttf/comic_sans.ttf");

   setWindow(new sf::RenderWindow);
   sf::ContextSettings settings;
   settings.antialiasingLevel = 8;
   getWindow()->create(sf::VideoMode(526, 526), "Yoba Snake", sf::Style::Close, settings);
   getWindow()->setFramerateLimit(60);
   getWindow()->setIcon(16, 16, Resources::get().getTexture("icon")->copyToImage().getPixelsPtr());

   _game = new Game;
   _game->onInit();

   _menu = new MainMenu;
   _menu->onInit();

   State::get().mode = State::Game;
}

void Application::clean()
{
   _game->onClean();
   _menu->onClean();
}

void Application::input()
{
   sf::Event event;
   while(getWindow()->pollEvent(event))
   {
      if(event.type == sf::Event::Closed)
         getWindow()->close();

      switch(State::get().mode)
      {
         case State::Game:
            _game->onEvent(event);
            break;

         case State::MainMenu:
            _menu->onEvent(event);
            break;
      }
   }

   if(!State::get().running)
      getWindow()->close();
}

void Application::update()
{
   switch(State::get().mode)
   {
      case State::Game:
         _game->onUpdate();
         break;

      case State::MainMenu:
         _menu->onUpdate();
         break;
   }
}

void Application::render()
{
   switch(State::get().mode)
   {
      case State::Game:
         _game->onRender(getWindow());
         break;

      case State::MainMenu:
         _menu->onRender(getWindow());
         break;
   }

   getWindow()->display();
}
