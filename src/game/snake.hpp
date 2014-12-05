#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "engine/common.hpp"

struct Segment
{
   Segment * previous = nullptr;
   Segment * next = nullptr;
   sf::Vector2i pos;

   bool hasPrevious() const;
   bool hasNext() const;

   bool hasLeft() const;
   bool hasRight() const;
   bool hasUpper() const;
   bool hasLower() const;
};

class Snake
{
public:
   enum Direction
   {
      Left,
      Right,
      Up,
      Down,
      None
   };

public:
   void update();

   void addSegment(Segment * segment);

   bool hasHead() const;
   Segment * getHead() const;

   Segment * getTail() const;

   Direction getDir() const;
   void setDir(Direction dir);

   sf::Vector2i getNextPos() const;

   int getSize() const { return _size; }

private:
   Segment * _head = nullptr;
   Segment * _tail = nullptr;

   Direction _dir = None;

   int _size = 0;
};

#endif // SNAKE_HPP
