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

void threadFn(std::promise<int>& prom)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  prom.set_value(200);
}

int main()
{
  std::promise<int> myPromise;
  std::future<int> fut = myPromise.get_future();
  std::cout << "Main..." << std::endl;

  std::thread t1(threadFn, std::ref(myPromise));
  t1.join();

  std::cout << "Main thread -> " << fut.get() << std::endl;
  return 0;
}