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
    *(ent.first_empty) = input;
    if (ent.current == nullptr)
    {
      ent.current = ent.first_empty;
    }
    // select next location
    if (ent.first_empty < ent.container + ent.maxsize)
    {
      ent.first_empty++;
    }
    else if (ent.current != ent.container)
    {
      ent.first_empty = ent.container;
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
  if (this->current != nullptr && this->current != this->first_empty)
  {
    int result = 0x80;
    if (this->current < (this->container + this->maxsize))
    {
      result = *(this->current);
    }
    if (this->current < (this->container + this->maxsize - 1))
    {
      this->current++;
    }
    else
    {
      this->current = this->container;
    }
    return result;
  }
  else
  {
    return 0;
  }
}
