/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <chrono>

int findMax(int arr[], int n)
{
  int max = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int findMax2(int arr[], int l, int r)
{
  if (l == r)
  {
    return arr[l];
  }
  int m = (l + r) / 2;
  int max1 = findMax2(arr, l, m);
  int max2 = findMax2(arr, m + 1, r);
  return std::max(max1, max2);
}

int main()
{
  int n = 10000000;
  int* arr = new int[n];
  int result = 0;
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 10000;
  }
  {
    auto start = std::chrono::high_resolution_clock::now();
    result = findMax(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << "s " << std::endl;

    std::cout << "result: " << result << std::endl;
  }
  {
    auto start = std::chrono::high_resolution_clock::now();
    result = findMax2(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << "s " << std::endl;

    std::cout << "result: " << result << std::endl;
  }
}