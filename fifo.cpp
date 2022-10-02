#include "fifo.hpp"

Fifo::Fifo()
{
  this->current     = nullptr;
  this->first_empty = container;
  this->counter     = 0;
  this->state       = State::EMPTY;
}
Fifo::~Fifo() {}

bool operator>>(Fifo& ent, const int& input)
{
  switch (ent.state)
  {
  case State::FULL:
    return false;

  case State::NORMAL:
    if (ent.first_empty != nullptr)
    {
      *(ent.first_empty) = input;
    }
    ent.counter++;
    if (ent.counter < ent.maxsize)
    {
      ent.increment_pointer(&ent.first_empty);
      ent.state = State::NORMAL;
    }
    else
    {
      ent.first_empty = nullptr;
      ent.state       = State::FULL;
    }
    return true;

  case State::EMPTY:
    if (ent.first_empty == nullptr)
      ent.first_empty = ent.container;
    *(ent.first_empty) = input;
    ent.counter++;
    ent.current = ent.first_empty;
    if (ent.counter < ent.maxsize)
    {
      ent.increment_pointer(&ent.first_empty);
      ent.state = State::NORMAL;
    }
    else
    {
      ent.first_empty = nullptr;
      ent.state       = State::FULL;
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
  int result;
  switch (state)
  {
  case State::NORMAL:
    result = *(this->current);
    counter--;
    if (counter == 0)
    {
      state = State::EMPTY;
    }
    else
    {
      increment_pointer(&this->current);
    }
    return result;

  case State::FULL:
    result = *(this->current);
    counter--;
    if (counter == 0)
    {
      state = State::EMPTY;
    }
    else
    {
      increment_pointer(&this->current);
      state = State::NORMAL;
    }
    return result;

  case State::EMPTY:
    return 123456;
  default:
    return 696969;
  }
}

bool Fifo::increment_pointer(int** ptr)
{
  if (*ptr < this->container + this->maxsize - 1)
  {
    (*ptr)++;
  }
  else
  {
    *ptr = container;
  }
  return true;
}
