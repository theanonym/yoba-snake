#include "snake.hpp"

bool Segment::hasPrevious() const
{
   return previous != nullptr;
}

bool Segment::hasNext() const
{
   return next != nullptr;
}

bool Segment::hasLeft() const
{
   if(hasPrevious())
   {
      if(pos.x - previous->pos.x == 1) return true;
      if(pos.x == 0 && previous->pos.x == 20) return true;
   }

   if(hasNext())
   {
      if(pos.x - next->pos.x == 1) return true;
      if(pos.x == 0 && next->pos.x == 20) return true;
   }

   return false;
}

bool Segment::hasRight() const
{
   if(hasPrevious())
   {
      if(previous->pos.x - pos.x == 1) return true;
      if(pos.x == 20 && previous->pos.x == 0) return true;
   }

   if(hasNext())
   {
      if(next->pos.x - pos.x == 1) return true;
      if(pos.x == 20 && next->pos.x == 0) return true;
   }

   return false;
}

bool Segment::hasUpper() const
{
   if(hasPrevious())
   {
      if(pos.y - previous->pos.y == 1) return true;
      if(pos.y == 0 && previous->pos.y == 20) return true;
   }

   if(hasNext())
   {
      if(pos.y - next->pos.y == 1) return true;
      if(pos.y == 0 && next->pos.y == 20) return true;
   }

   return false;
}

bool Segment::hasLower() const
{
   if(hasPrevious())
   {
      if(previous->pos.y - pos.y == 1) return true;
      if(pos.y == 20 && previous->pos.y == 0) return true;
   }

   if(hasNext())
   {
      if(next->pos.y - pos.y == 1) return true;
      if(pos.y == 20 && next->pos.y == 0) return true;
   }

   return false;

}

void Snake::update()
{
   Segment * node = getHead();
   sf::Vector2i previousPos = node->pos;
   node->pos = getNextPos();
   while(node->hasNext())
   {
      node = node->next;
      std::swap(node->pos, previousPos);
   }
}

bool Snake::hasHead() const
{
   return _head != nullptr;
}

Segment * Snake::getHead() const
{
   assert(_head);
   return _head;
}

Segment * Snake::getTail() const
{
   assert(_tail);
   return _tail;
}

void Snake::addSegment(Segment * segment)
{
   assert(segment);
   if(hasHead())
   {
      _tail->next = segment;
      segment->previous = _tail;
   }
   else
   {
      _head = segment;
   }

   _tail = segment;
   _size++;
}

Snake::Direction Snake::getDir() const
{
   return _dir;
}

void Snake::setDir(Snake::Direction dir)
{
   _dir = dir;
}

sf::Vector2i Snake::getNextPos() const
{
   sf::Vector2i pos = getHead()->pos;
   switch(getDir())
   {
      case Left:  pos.x -= 1; break;
      case Right: pos.x += 1; break;
      case Up:    pos.y -= 1; break;
      case Down:  pos.y += 1; break;
      case None: break;
   }

   if(pos.x < 0) pos.x = 20;
   if(pos.y < 0) pos.y = 20;
   if(pos.x > 20) pos.x = 0;
   if(pos.y > 20) pos.y = 0;

   return pos;
}


