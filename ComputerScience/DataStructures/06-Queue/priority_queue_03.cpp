/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <queue>

int main()
{
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::priority_queue<int> pq(arr, arr + 10);

  while (!pq.empty())
  {
    std::cout << pq.top() << std::endl;
    pq.pop();
  }

  return 0;
}