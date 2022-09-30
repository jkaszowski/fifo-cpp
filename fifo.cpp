#include "fifo.hpp"

Fifo::Fifo()
{
  this->current     = nullptr;
  this->first_empty = container;
}
Fifo::~Fifo() {}

bool operator>>(Fifo& ent, const int& input)
{
  if (ent.current == ent.first_empty)
  {
    // fifo is full
    return false;
  }
  else
  {
    // copy input into fifo
    if (ent.first_empty < ent.container + ent.maxsize && ent.first_empty != nullptr)
    {
      *(ent.first_empty) = input;
    }
    if (ent.current == nullptr)
    {
      ent.current = ent.first_empty;
    }
    // select next location
    if (ent.first_empty < ent.container + ent.maxsize)
    {
      ent.first_empty++;
    }
    else
    {
      ent.first_empty = (ent.current != ent.container ? ent.container : nullptr);
    }
    return true;
  }
}
std::ostream& operator<<(std::ostream& os, Fifo& ent)
{
  /*for (size_t i = 0; i < maxsize; i++) {
    os << "Element " << i << ": " << ent.container[i] << std::endl;
  }*/
  os << ent.getFirst();
  return os;
}

const int Fifo::getFirst()
{
  int result = 0;
  // read value from current location
  if (current < (container + maxsize) && current != nullptr)
  {
    result = *(current);
  }
  // if you can increment without exceeding, do that
  if (current < (container + maxsize - 1))
  {
    current++;
  }
  // if you exceed with incrementing, check what is the state of first_empty
  else if (first_empty != nullptr)
  {
    current = container;
  }
  return result;
}
