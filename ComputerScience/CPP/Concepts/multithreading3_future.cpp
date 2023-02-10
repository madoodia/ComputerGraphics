/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <cstdlib>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

int asyncFunc(int value)
{
  std::cout << "Inside an async function!" << std::endl;
  return value + 100;
}

int main()
{

  std::future<int> fu1 = std::async(std::launch::async, asyncFunc, 100);
  if (fu1.valid())
    std::cout << fu1.get() << std::endl;
  else
    std::cout << "Invalid!" << std::endl;

  int value1 = 500;

  std::future<int> fu2 = std::async(
      std::launch::async,
      [&value1](int x)
      { value1 *= x; return 393939; },
      2);
  if (fu2.valid())
  {
    std::cout << fu2.get() << std::endl;
    std::cout << "value1: " << value1 << std::endl;
  }
  else
  {
    std::cout << "Invalid!" << std::endl;
  }

  return 0;
}