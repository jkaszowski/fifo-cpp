#include "fifo.hpp"

Fifo::Fifo() {}
Fifo::~Fifo() {}

bool operator<<(Fifo& ent, int&& input)
{
  if (ent.current == ent.first_empty || ent.first_empty == nullptr)
  {
    // it means that the fifo is full
    return false;
  }
  else
  {
    *(ent.first_empty) = input;
    if (ent.current == nullptr)
    {
      ent.current = ent.first_empty;
    }
    if (ent.first_empty < ent.container + maxsize)
    {
      ent.first_empty++;
    }
    else
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
  int result = *(this->current++);
  return result;
}
