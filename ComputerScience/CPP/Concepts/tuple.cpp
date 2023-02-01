/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <utility>

int main()
{
  std::tuple<int, double, float, std::string> t1(1, 2.3, 4.5, "Hello");
  std::tuple<int, double, std::vector<int>> t2(1, 2.3, {1, 2, 3, 4, 5});
  std::tuple<int, std::string> t3(3, "Hello");

  auto t = std::make_tuple(1, 2.3, 4.5, "Hello");

  std::cout << std::get<0>(t1) << " " << std::get<1>(t1) << std::endl;
  std::cout << std::get<2>(t2) << " " << std::get<1>(t2) << std::endl;
  std::cout << std::get<0>(t3) << " " << std::get<1>(t3) << std::endl;

  return 0;
}