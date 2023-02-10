/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::condition_variable cv;
std::mutex m;
bool ready = false; // shared resource by main() and worker_thread()

void worker_thread()
{
  // Wait until main() sends data
  {
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, []
            { return ready; });
  }

  std::cout << "Worker thread is processing data." << std::endl;
}

int main()
{
  std::thread worker(worker_thread);

  std::cout << "Main thread is preparing data." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));

  // Send data to the worker thread
  {
    std::lock_guard<std::mutex> lock(m);
    ready = true;
  }
  cv.notify_one();

  worker.join();

  return 0;
}
