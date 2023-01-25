/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

int main()
{

  int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  int low = 0;
  int mid = 0;
  int high = size - 1;

  while (mid <= high)
  {
    switch (arr[mid])
    {
    case 0:
      std::swap(arr[low++], arr[mid++]);
      break;
    case 1:
      mid++;
      break;
    case 2:
      std::swap(arr[mid], arr[high--]);
      break;
    }
  }

  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i];
  }
  
  return 0;
}