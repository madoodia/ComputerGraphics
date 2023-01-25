/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/


#include <iostream>

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
  

  return 0;
}