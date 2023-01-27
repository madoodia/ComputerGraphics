/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

void merge_sort(int* arr, int start, int end)
{
  if (start >= end)
    return;

  int mid = (start + end) / 2;
  merge_sort(arr, start, mid);
  merge_sort(arr, mid + 1, end);

  int* temp = new int[end - start + 1];
  int i = start;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= end)
  {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  while (i <= mid)
    temp[k++] = arr[i++];

  while (j <= end)
    temp[k++] = arr[j++];

  for (i = start; i <= end; i++)
    arr[i] = temp[i - start];
}

int main()
{
  int arr[] = { 5, 1, 3, 2, 4 };
  int n = sizeof(arr) / sizeof(arr[0]);

  merge_sort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";

  return 0;
}