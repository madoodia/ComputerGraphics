/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <chrono>

// selection sort
void selectionSort(int array[], int size) // O(n^2), no extra space
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (array[i] > array[j])
      {
        std::swap(array[i], array[j]);
      }
    }
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

  selectionSort(array, size);

  for (int i = 0; i < size; i++)
  {
    std::cout << array[i] << std::endl;
  }

  return 0;
}