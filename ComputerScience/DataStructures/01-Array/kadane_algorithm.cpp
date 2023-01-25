/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

int main()
{
  int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
  int size = sizeof(arr) / sizeof(arr[0]);

  int max_so_far = arr[0];
  int max_ending_here = arr[0];

  for (int i = 1; i < size; i++)
  {
    max_ending_here = std::max(arr[i], max_ending_here + arr[i]);
    max_so_far = std::max(max_so_far, max_ending_here);
  }

  std::cout << max_so_far << std::endl;

  return 0;
}