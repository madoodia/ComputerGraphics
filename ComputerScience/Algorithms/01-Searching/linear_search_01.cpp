/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <vector>

void search(int arr[], int size, int n)
{
  // search for n in arr
  ;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == n)
    {
      std::cout << "Found " << n << " at index " << i << std::endl;
      return;
    }
    i++;
  }
  std::cout << "Not found " << n << std::endl;
}

void search2(std::vector<int> vec, int key)
{
  // std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), key);
  // or
  auto it = std::find(vec.begin(), vec.end(), key);
  if (it != vec.end())
    std::cout << "Found " << key << " at index " << std::distance(vec.begin(), it) << std::endl;
  else
    std::cout << "Not found " << key << std::endl;
}

int main()
{

  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  int n = 4;

  search(arr, size, n);

  return 0;
}