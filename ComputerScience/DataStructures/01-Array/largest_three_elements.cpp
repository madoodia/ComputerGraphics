/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

// how to return array from a function
// https://stackoverflow.com/questions/1416873/how-to-return-array-from-a-function-in-c

int* findLargests(int arr[], int size)
{
  int* largest = new int[3];

  if (size < 3)
  {
    std::cout << "Invalid Input" << std::endl;
    return 0;
  }

  for (int i = 0; i < size; i++)
  {
    if (arr[i] > largest[0])
    {
      largest[2] = largest[1];
      largest[1] = largest[0];
      largest[0] = arr[i];
    }
    else if (arr[i] > largest[1])
    {
      largest[2] = largest[1];
      largest[1] = arr[i];
    }
    else if (arr[i] > largest[2])
    {
      largest[2] = arr[i];
    }
  }

  for (int i = 0; i < 3; i++)
  {
    arr[i] = i;
  }

  return largest;
}

int main()
{
  // an array of distinct numbers
  int arr[] = {12, 13, 1, 10, 34, 1, 21, 4, 22, 15};

  int* largest = findLargests(arr, sizeof(arr) / sizeof(arr[0]));

  std::cout << arr[0] << std::endl;

  std::cout << "Largest 3 elements are: " << largest[0] << " " << largest[1] << " " << largest[2] << std::endl;

  delete[] largest;

  return 0;
}