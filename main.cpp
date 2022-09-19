#include "fifo.hpp"
#include <iostream>

Fifo kolejka;

int main()
{
  for (int i = 0; i < 130; i++)
  {
    kolejka >> i;
  }
  for (int i = 0; i < 140; i++)
  {
    std::cout << kolejka << std::endl;
  }
  return 0;
}
