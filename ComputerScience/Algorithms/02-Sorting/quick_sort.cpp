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

void quick_sort2(int* arr, int left, int right)
{
  int pivot = (left + right) / 2;
  int l = left;
  int r = right - 1;
  std::swap(arr[pivot], arr[right]);

  while (l <= r)
  {
    while (arr[l] < arr[right])
      l++;
    while (arr[r] > arr[right])
      r--;
    if (l <= r)
    {
      std::swap(arr[l], arr[r]);
      l++;
      r--;
    }
  }

  if (left < r)
    quick_sort2(arr, left, r);
  if (l < right)
    quick_sort2(arr, l, right);
}

// -----------------------------
int main()
{
  int arr1[] = {7, 9, 1, 5, 6, 4, 3, 8, 2, 10};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  {
    // quick_sort(arr1, 0, n1 - 1);
    quick_sort2(arr1, 0, n1 - 1);
  }
  for (int i = 0; i < n1; i++)
    std::cout << arr1[i] << " ";
  std::cout << std::endl;

  return 0;
}