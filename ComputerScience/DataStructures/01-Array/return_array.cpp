/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

int* createArray(int size)
{
  int* arr = new int[size];
  for (int i = 0; i < size; i++)
  {
    arr[i] = i;
  }
  return arr;
}

int main()
{
  int size = 10;
  int* myArray = createArray(size);
  for (int i = 0; i < size; i++)
  {
    std::cout << myArray[i] << " ";
  }
  std::cout << std::endl;
  delete[] myArray;
  return 0;
}
