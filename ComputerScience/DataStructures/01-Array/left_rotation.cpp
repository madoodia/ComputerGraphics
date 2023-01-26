/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

void rotate1(int arr[], int d, int size)
{
  // rotate array
  if (d <= 0)
    return;

  int* temp = new int[d];

  for (int i = 0; i < d; i++)
  {
    temp[i] = arr[i];
  }
  for (int i = 0; i < size - 1; i++)
  {
    arr[i] = arr[i + d];
  }
  for (int i = 0; i < d; i++)
  {
    arr[size - d + i] = temp[i];
  }
}
void rotate2(int arr[], int d, int n)
{
  int p = 1;
  while (p <= d)
  {
    int last = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
    arr[n - 1] = last;
    p++;
  }
}

int main()
{

  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 3;

  // print original array
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  rotate1(arr, d, size);
  rotate2(arr, d, size);

  // print rotated array
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}