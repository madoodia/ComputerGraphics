/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);

void increment_counter()
{
  for (int i = 0; i < 100000; ++i)
  {
    ++counter;
  }
}

int main()
{
  std::thread t1(increment_counter);
  std::thread t2(increment_counter);

  t1.join();
  t2.join();

  std::cout << "Counter: " << counter << std::endl;

  return 0;
}
