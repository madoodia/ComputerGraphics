/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <utility>
#include <string>

int main()
{
  std::pair<int, int> p1(1, 2);
  std::pair<int, double> p2(3, 4.8);
  std::pair<int, std::string> p3(3, "Hello");

  std::cout << p1.first << " " << p1.second << std::endl;
  std::cout << p2.first << " " << p2.second << std::endl;
  std::cout << p3.first << " " << p3.second << std::endl;

  return 0;
}