/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <set>
#include <iostream>

int main()
{
  std::multiset<int> c = {1, 2, 3, 4, 1, 2, 3, 4};
  auto print = [&c]()
  {
    for (auto i : c)
      std::cout << i << " ";
    std::cout << std::endl;
  };

  print();

  return 0;
}