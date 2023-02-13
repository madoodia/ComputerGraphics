/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <chrono>

long long SumOfSquares(long long n)
{
  long long sum = 0;
  for (long long i = 1; i <= n; i++)
    sum += i * i;
  return sum;
}

long long SumOfSquares2(long long n)
{
  return n * (n + 1) * (2 * n + 1) / 6;
}

int main()
{
  long long n = 100;
  long long result = 0;
  {
    auto start = std::chrono::high_resolution_clock::now();
    result = SumOfSquares(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << "s " << std::endl;

    std::cout << "result: " << result << std::endl;
  }
  {
    auto start = std::chrono::high_resolution_clock::now();
    result = SumOfSquares2(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << "s " << std::endl;

    std::cout << "result: " << result << std::endl;
  }
}