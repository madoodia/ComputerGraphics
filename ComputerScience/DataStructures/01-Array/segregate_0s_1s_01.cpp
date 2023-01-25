/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <chrono>

/*
Result for a Bilion data on heap
blockMemorySize = 3.89484e+06 [GB]
Time of filling the array = 58.5234 [second]
Time difference 01 = 6.91223 [second]
Time difference 02 = 1.70561 [second]
Time difference 03 = 1.59094[second]
*/
void segregate0s1s_01(int arr[], int size)
{
  int localSize = sizeof(arr) / sizeof(arr[0]); // this is wrong for getting the size of the array

  unsigned int onesCount = 0;
  unsigned int zerosCount = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] == 0)
      zerosCount++;
  }

  onesCount = size - zerosCount;

  for (int i = 0; i < zerosCount; i++)
  {
    arr[i] = 0;
  }

  for (int i = zerosCount; i < size; i++)
  {
    arr[i] = 1;
  }
}

void segregate0s1s_02(int arr[], int size)
{

  int left = 0;
  int right = size - 1;

  while (left < right)
  {
    while (arr[left] == 0 && left < right)
      left++;
    while (arr[right] == 1 && left < right)
      right--;
    if (left < right)
    {
      arr[left] = 0;
      arr[right] = 1;
      left++;
      right--;
    }
  }
}

void segregate0s1s_03(int arr[], int size)
{
  int type0 = 0;
  int type1 = size - 1;

  while (type0 < type1)
  {
    if (arr[type0] == 1)
    {
      if (arr[type1] != 1)
      {
        std::swap(arr[type0], arr[type1]);
      }
      type1--;
    }
    else
    {
      type0++;
    }
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{

  std::chrono::steady_clock::time_point start;
  std::chrono::steady_clock::time_point end;
  // int array[] = {0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1};
  int size = 1000000000;
  float blockMemorySize = (float)sizeof(int) * size / (1024 ^ 3);
  std::cout << "blockMemorySize = " << blockMemorySize << " [GB]" << std::endl;

  int* array = new int[size]{};

  start = std::chrono::steady_clock::now();
  for (int i = 0; i < size; i++)
  {
    array[i] = rand() % 2;
  }
  end = std::chrono::steady_clock::now();
  std::cout << "Time of filling the array = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << " [second]" << std::endl;

  start = std::chrono::steady_clock::now();
  segregate0s1s_01(array, size);
  end = std::chrono::steady_clock::now();
  std::cout << "Time difference 01 = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << " [second]" << std::endl;
  // printArray(array, size);
  start = std::chrono::steady_clock::now();

  segregate0s1s_02(array, size);
  end = std::chrono::steady_clock::now();
  std::cout << "Time difference 02 = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << " [second]" << std::endl;
  // printArray(array, size);
  start = std::chrono::steady_clock::now();

  segregate0s1s_03(array, size);
  end = std::chrono::steady_clock::now();
  std::cout << "Time difference 03 = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / (1e+6) << "[second]" << std::endl;
  // printArray(array, size);

  delete[] array;

  return 0;
}