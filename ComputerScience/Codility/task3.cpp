
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int solution1(vector<int>& A)
{
  vector<int> result{};
  int max = 1;

  for (unsigned int i = 0; i < A.size() - 1; i++)
  {
    for (unsigned int j = i; j < A.size(); j++)
    {
      if (A[j] >= 0)
        result.push_back(A[j]);
      else
        break;

      if (A[j + 1] <= 0)
        result.push_back(A[j + 1]);
      else
        break;
      j++;
    }
    if (result.size() > max)
      max = result.size();
    result.clear();
  }
  return max;
}

int solution2(vector<int>& A)
{
  vector<int> result{};
  int max = 1;

  for (unsigned int i = 0; i < A.size(); i++)
  {
    if (A[i] >= 0)
    {
      result.push_back(A[i]);
      i++;
      while (i < A.size() && A[i] <= 0)
      {
        result.push_back(A[i]);
        i++;
      }
    }
    else
    {
      result.push_back(A[i]);
      i++;
      while (i < A.size() && A[i] >= 0)
      {
        result.push_back(A[i]);
        i++;
      }
    }
    if (result.size() > max)
      max = result.size();
    result.clear();
  }
  return max;
}

int main()
{
  // vector<int> A{5, 4, -3, 2, 0, 1, -1, 0, 2, -3, 4, -5};
  // vector<int> A{1, 2, 3};

  std::chrono::time_point<std::chrono::system_clock> start, end;
  int size = 10000;
  std::vector<int>* A = new std::vector<int>(size);

  for (int i = 0; i < size; i++)
    // fill the array with random signed number in range [-100, 100]
    (*A)[i] = rand() % 201 - 100;
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