/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <chrono>

// selection sort
void selectionSort(int array[], int size) // O(n^2), no extra space
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (array[i] > array[j])
      {
        std::swap(array[i], array[j]);
      }
    }
  }
}

void binarySearch(int array[], int size, int key)
{
  int low = 0;
  int high = size - 1;
  int mid = (low + high) / 2;

  while (low <= high)
  {
    if (array[mid] == key)
    {
      std::cout << "Found at index: " << mid << std::endl;
      return;
    }
    else if (array[mid] < key)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
    mid = (low + high) / 2;
  }
  std::cout << "Not found!" << std::endl;
}

void binarySearch(int array[], int key, int low, int high)
{
  if (low > high)
  {
    std::cout << "Not found!" << std::endl;
    return;
  }

  int mid = (low + high) / 2;

  if (array[mid] == key)
  {
    std::cout << "Found at index: " << mid << std::endl;
    return;
  }
  else if (array[mid] < key)
    binarySearch(array, key, mid + 1, high);
  else
    binarySearch(array, key, low, mid - 1);
}

int main()
{
  std::chrono::steady_clock::time_point start;
  std::chrono::steady_clock::time_point end;
  int size = 100;
  int* array = new int[size];
  // int size = sizeof(array) / sizeof(array[0]);
  int key = 4;

  start = std::chrono::steady_clock::now();
  for (int i = 0; i < size; i++)
  {
    array[i] = rand();
  }
  end = std::chrono::steady_clock::now();
  std::cout << "Time of filling the array = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << " [second]" << std::endl;

  start = std::chrono::steady_clock::now();
  selectionSort(array, size);
  end = std::chrono::steady_clock::now();
  std::cout << "Time of sorting the array = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << " [second]" << std::endl;

  start = std::chrono::steady_clock::now();
  binarySearch(array, size, key);
  end = std::chrono::steady_clock::now();
  std::cout << "Time of binarySearch1 = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << " [second]" << std::endl;

  start = std::chrono::steady_clock::now();
  binarySearch(array, key, 0, size - 1);
  end = std::chrono::steady_clock::now();
  std::cout << "Time of binarySearch2 = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << " [second]" << std::endl;

  return 0;
}