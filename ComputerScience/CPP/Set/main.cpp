/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <vector>
#include <set>

int main()
{
  std::vector<int> myvector = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};
  std::set<int> myset(myvector.begin(), myvector.end());

  std::cout << "myset contains:";
  for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
    std::cout << ' ' << *it;

  return 0;
}