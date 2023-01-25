/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <array>
#include <vector>
#include <string>

int main()
{
  std::array<int, 9> array1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> array2{1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::array<std::string, 3> array3{"a", "b", "c"};
  std::vector<std::string> array4{"a", "b", "c"};

  std::array<std::array<int, 3>, 3> array5{1, 2, 3,
                                           4, 5, 6,
                                           7, 8, 9};
  std::array<std::array<std::string, 3>, 3> array6{"a", "b", "c",
                                                   "d", "e", "f",
                                                   "g", "h", "i"};
}
