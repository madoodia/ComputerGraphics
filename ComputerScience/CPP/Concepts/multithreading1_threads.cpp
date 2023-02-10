/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

int threadFunction(const int* array, int start, int end)
{
  // std::this_thread::sleep_for(std::chrono::milliseconds(100));
  int count = 0;
  for (int i = start; i < end; i++)
  {
    if (array[i] % 2 == 0)
      count++;
  }
  return count;
}

int main()
{
  const int size = 1000;
  int* array = new int[size];

  std::chrono::steady_clock::time_point begin;
  std::chrono::steady_clock::time_point end;

  // randomly fill the array ------------------------------------------
  for (int i = 0; i < size; i++)
  {
    array[i] = rand() % 1000;
  }

  // // print the array ------------------------------------------
  // for (int i = 0; i < size; i++)
  // {
  //   std::cout << array[i] << " ";
  // }
  // std::cout << std::endl;

  // begin = std::chrono::steady_clock::now();
  // threadFunction(array, 0, size);
  // end = std::chrono::steady_clock::now();
  // std::cout << "Single thread: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;

  int threadCount = 8;
  std::vector<std::thread> threads;
  int chunkSize = size / threadCount;

  // // without future ------------------------------------------
  // for (int i = 0; i < threadCount; i++)
  // {
  //   int start = i * chunkSize;
  //   int end = (i + 1) * chunkSize;
  //   if (i == threadCount - 1)
  //     end = size;
  //   threads.push_back(std::thread(threadFunction, array, start, end));
  // }
  // begin = std::chrono::steady_clock::now();
  // for (int i = 0; i < threadCount; i++)
  // {
  //   threads[i].join();
  // }
  // end = std::chrono::steady_clock::now();
  // std::cout << "Multi thread: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;

  // with future ------------------------------------------
  int count = 0;
  begin = std::chrono::steady_clock::now();
  for (int i = 0; i < threadCount; i++)
  {
    std::future<int> future = std::async(std::launch::async, threadFunction, array, i * chunkSize, (i + 1) * chunkSize);
    count += future.get();
  }
  end = std::chrono::steady_clock::now();
  std::cout << "Multi thread: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
  std::cout << "Count: " << count << std::endl;

  return 0;
}
