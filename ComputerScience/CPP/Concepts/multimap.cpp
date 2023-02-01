/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <map>
#include <iostream>

int main()
{
  std::multimap<int, std::string> c = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {1, "one"}};

  for (auto it = c.begin(); it != c.end();)
  {
    if (it->first % 2 != 0) // erase all odd numbers from c
      it = c.erase(it);
    else
      ++it;
  }

  for (auto& p : c)
    std::cout << p.second << ' ';
}