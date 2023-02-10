/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <cstdlib>

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void threadFn(std::mutex& mtx)
{
  std::lock_guard<std::mutex> guard(mtx);
  std::cout << "inside the thread func!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main()
{
  std::mutex mtx;
  std::thread t1(threadFn, std::ref(mtx));
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  t1.join();

  std::cout << "Main thread" << std::endl;
  return 0;
}