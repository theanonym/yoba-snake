#ifndef STATE_HPP
#define STATE_HPP

#include "engine/singleton.hpp"

class State : public Singleton<State>
{
public:
   enum Mode
   {
      Game,
      MainMenu
   } mode;

   struct
   {
      bool isPaused = false;
      bool isStarted = false;
      bool isGameOver = false;
      int scores = 0;
   } game;

   bool running = true;
};

#endif // STATE_HPP
