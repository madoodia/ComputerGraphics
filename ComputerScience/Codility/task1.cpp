#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>

int solution1(std::vector<int>& A)
{
  int N = A.size();
  int result = 0;

  for (int i = 0; i < N; i++)
    for (int j = N - 1; j > i; j--)
      if (A[i] == A[j])
      {
        result = std::max(result, abs(i - j));
        return result;
      }
  return result;
}

int solution2(std::vector<int>& A)
{
  int N = A.size();
  int result = 0;
  std::vector<int> positions(N, -1);
  for (int i = 0; i < N; i++)
  {
    if (positions[A[i]] != -1)
    {
      result = std::max(result, i - positions[A[i]]);
    }
    else
    {
      positions[A[i]] = i;
    }
  }
  return result;
}

int main()
{
  // std::vector<int> A{2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  // std::cout << solution(A) << std::endl;

  std::chrono::time_point<std::chrono::system_clock> start, end;
  int size = 10000;
  std::vector<int>* A = new std::vector<int>(size);

  for (int i = 0; i < size; i++)
    (*A)[i] = rand() % 100;
  {
    start = std::chrono::system_clock::now();
    std::cout << solution1(*A) << std::endl;
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
  }
  {
    start = std::chrono::system_clock::now();
    std::cout << solution2(*A) << std::endl;
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
  }
  return 0;
}