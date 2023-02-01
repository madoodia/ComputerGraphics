#include <algorithm>
#include <vector>

int solution(vector<int>& A)
{
  int N = A.size();
  int result = 0;

  for (int i = 0; i < N - 2; i++)
    for (int j = N - 1; j > i; j--)
      if (A[i] == A[j])
      {
        result = max(result, abs(i - j));
        return result;
      }
  return result;
}