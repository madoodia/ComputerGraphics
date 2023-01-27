/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <chrono>

// bubble sort
void bubbleSort(int array[], int size) // O(n^2), no extra space
{
  int i = 0;
  while (i < size)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        std::swap(array[j], array[j + 1]);
      }
    }
    i++;
  }
}

int main()
{
  int size = 10;
  int* array = new int[size];
  // int size = sizeof(array) / sizeof(array[0]);
  int key = 4;

  for (int i = 0; i < size; i++)
  {
    array[i] = rand();
  }

  return 0;
}