/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

void rightRotate1(int arr[], int d, int size)
{
  // rotate array
  if (d <= 0)
    return;

  int* temp = new int[d];

  for (int i = (size - d); i < size; i++)
  {
    temp[i - (size - d)] = arr[i];
  }
  for (int i = (size - d - 1); i >= 0; i--)
  {
    arr[i + d] = arr[i];
  }
  for (int i = 0; i < d; i++)
  {
    arr[i] = temp[i];
  }

  delete[] temp;
}
void rightRotate2(int arr[], int d, int n)
{
  int p = 1;
  while (p <= d)
  {
    int last = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
      arr[i] = arr[i - 1];
    }
    arr[0] = last;
    p++;
  }
}

int main()
{

  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 4;

  // print original array
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  // rightRotate1(arr, d, size);
  rightRotate2(arr, d, size);

  // print rotated array
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}