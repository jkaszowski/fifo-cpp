#include "fifo.hpp"
#include <iostream>

Fifo kolejka;

int main()
{
  kolejka << 1;
  kolejka << 2;
  std::cout << kolejka << std::endl << kolejka << std::endl;

  return 0;
}
