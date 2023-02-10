/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <cstdlib>

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// condition_varicables are used as a Signal Mechanism between threads

void threadFn(std::mutex& mtx, std::condition_variable& convar)
{
  std::unique_lock<std::mutex> lock(mtx);
  convar.wait(lock);
  std::cout << "End of thread..." << std::endl;
}

int main()
{
  std::mutex mtx;
  std::condition_variable convar;
  std::thread t1(threadFn, std::ref(mtx), std::ref(convar));
  std::this_thread::sleep_for(std::chrono::seconds(5));
  {
    std::lock_guard<std::mutex> guard(mtx);
    convar.notify_all();
  }

  t1.join();

  std::cout << "End of main..." << std::endl;
  return 0;
}