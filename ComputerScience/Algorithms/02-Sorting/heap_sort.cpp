/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <algorithm>
#include <chrono>

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i)
  {
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--)
  {
    std::swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

// or

void heapSort2(int arr[], int n)
{
  std::make_heap(arr, arr + n);
  std::sort_heap(arr, arr + n);
}

int main()
{
  std::chrono::steady_clock::time_point start;
  std::chrono::steady_clock::time_point end;
  int size = 1000000;
  {
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
      arr[i] = rand();
    }

    start = std::chrono::steady_clock::now();
    heapSort(arr, size);
    end = std::chrono::steady_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << " [second]" << std::endl;

    // std::cout << "Sorted array is \n";
    // for (int i = 0; i < size; ++i)
    //   std::cout << arr[i] << " ";
    // std::cout << std::endl;
  }

  {
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
      arr[i] = rand();
    }

    start = std::chrono::steady_clock::now();
    heapSort2(arr, size);
    end = std::chrono::steady_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << " [second]" << std::endl;

    // std::cout << "Sorted array is \n";
    // for (int i = 0; i < size; ++i)
    //   std::cout << arr[i] << " ";
    // std::cout << std::endl;
  }
  return 0;
}
