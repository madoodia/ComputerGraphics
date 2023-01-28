/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

// implement a sparse table algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// implement it with cout statements
// to see how it works

int main()
{
  vector<int> v = {4, 2, 3, 7, 1, 5, 3, 3, 9, 6, 7, -1, 4};
  int n = v.size();
  int p = 3;
  int k = pow(2, p);
  vector<vector<int>> st(n, vector<int>(k, 0));

  for (int i = 0; i < n; i++)
    st[i][0] = v[i];

  for (int j = 1; j < k; j++)
  {
    for (int i = 0; i + (1 << j) <= n; i++)
    {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      cout << st[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}