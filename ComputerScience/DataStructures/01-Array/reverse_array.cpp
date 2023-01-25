/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

void reverseArray(int arr[], int size)
{
  int temp;
  for (int i = 0; i < size / 2; i++)
  {
    // temp = arr[i];
    // arr[i] = arr[size - i - 1];
    // arr[size - i - 1] = temp;
    // or
    std::swap(arr[i], arr[size - i - 1]);
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i];
  }
  std::cout << std::endl;
}

int main()
{
  int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  printArray(arr, size);

  reverseArray(arr, size);

  printArray(arr, size);

  return 0;
}