/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <stdlib.h>

int main()
{

  // create random numbers of 0 and 1
  {
    int arr[10]{};
    for (int i = 0; i < 10; i++)
    {
      arr[i] = rand() % 2;
    }
  }

  // create random numbers in range of 0 to 3
  {
    int arr[10]{};
    for (int i = 0; i < 10; i++)
    {
      int random = rand();
      std::cout << "random = " << random << std::endl;
      arr[i] = random % 4;
    }
  }

  {
    std::cout << "RAND_MAX:" << RAND_MAX << std::endl;
    for (int i = 0; i < 10; i++)
    {
      std::cout << "Double Random:" << (double)rand() / RAND_MAX << std::endl; // make random nomber 0.0 to 1.0
    }
  }

  return 0;
}