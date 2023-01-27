/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

void quick_sort(int* arr, int left, int right)
{
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];
  /* partition */
  while (i <= j)
  {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j)
    {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  /* recursion */
  if (left < j)
    quick_sort(arr, left, j);
  if (i < right)
    quick_sort(arr, i, right);
}

// -----------------------------
int main()
{
  int arr1[] = {7, 9, 1, 5, 6, 4, 3, 8, 2, 10};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  {
    quick_sort(arr1, 0, n1 - 1);
  }
  for (int i = 0; i < n1; i++)
    std::cout
        << arr1[i] << " ";
  std::cout << std::endl;

  return 0;
}