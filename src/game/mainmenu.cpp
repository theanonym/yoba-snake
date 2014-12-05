#include "mainmenu.hpp"
#include "state.hpp"
#include "engine/resources.hpp"

void MainMenu::onInit()
{
   sf::Vector2f startPos(300, 330);

   sf::Text baseText(L"", *Resources::get().getFont("comic"), 30);
   baseText.setColor(sf::Color::Black);

   // Продолжить
   sf::Text continueText(baseText);
   continueText.setString(L"Продолжить");
   continueText.setPosition(startPos + sf::Vector2f(0, 0));
   _buttons.push_back(continueText);

   _callbacks.push_back(std::make_pair(sf::IntRect(continueText.getGlobalBounds()),
   []() {
      if(State::get().game.isStarted)
         State::get().mode = State::Game;
   }));

   // Новая игра
   sf::Text startText(baseText);
   startText.setString(L"Новая игра");
   startText.setPosition(startPos + sf::Vector2f(0, 50));
   _buttons.push_back(startText);

   _callbacks.push_back(std::make_pair(sf::IntRect(startText.getGlobalBounds()),
   []() {
      State::get().mode = State::Game;
      State::get().game.isStarted = false;
   }));


   // Выход
   sf::Text exitText(baseText);
   exitText.setString(L"Выход");
   exitText.setPosition(startPos + sf::Vector2f(0, 100));
   _buttons.push_back(exitText);

   _callbacks.push_back(std::make_pair(sf::IntRect(exitText.getGlobalBounds()),
   []() {
      State::get().running = false;
   }));
}

void MainMenu::onRender(sf::RenderWindow * window)
{
   window->clear(sf::Color(255, 226, 76));

   bool firstSkiped = false;
   for(sf::Text & button : _buttons)
   {
      if(!State::get().game.isStarted && !firstSkiped)
      {
         firstSkiped = true;
         continue;
      }

      if(button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
         button.setColor(sf::Color(130, 130, 130));
      else
         button.setColor(sf::Color::Black);

      window->draw(button);
   }
}

void MainMenu::onKeyPressed(const sf::Event::KeyEvent & event)
{
   if(event.code == sf::Keyboard::Escape)
      State::get().running = false;
}

void MainMenu::onMousePressed(const sf::Event::MouseButtonEvent & event)
{
   for(const auto & pair : _callbacks)
      if(pair.first.contains(sf::Vector2i(event.x, event.y)))
         pair.second();
}
