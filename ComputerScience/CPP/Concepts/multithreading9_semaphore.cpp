/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Semaphore
{
public:
  Semaphore(int count = 0) : count_(count) {}

  void Notify()
  {
    std::unique_lock<std::mutex> lock(mutex_);
    ++count_;
    cond_.notify_one();
  }

  void Wait()
  {
    std::unique_lock<std::mutex> lock(mutex_);
    cond_.wait(lock, [this]()
               { return count_ > 0; });
    --count_;
  }

private:
  int count_;
  std::mutex mutex_;
  std::condition_variable cond_;
};

Semaphore semaphore(0);

void worker_thread()
{
  semaphore.Wait();
  std::cout << "Worker thread started" << std::endl;
}

int main()
{
  std::thread t(worker_thread);

  std::cout << "Main thread started" << std::endl;
  semaphore.Notify();

  t.join();

  return 0;
}
