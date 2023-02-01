
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& A)
{
  vector<int> result{};
  int max = 1;

  for (unsigned int i = 0; i < A.size()-1; i++)
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

int main()
{
  // vector<int> A{5, 4, -3, 2, 0, 1, -1, 0, 2, -3, 4, -5};
  vector<int> A{1, 2, 3};
  cout << solution(A) << endl;
  return 0;
}