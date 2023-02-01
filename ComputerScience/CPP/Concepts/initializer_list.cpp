/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class A
{
public:
  A(std::initializer_list<int> list)
  {
    for (auto i : list)
      std::cout << i << std::endl;
  }
};

class B
{
public:
  int list[5]{};
  B()
  {
    for (auto i : list)
      std::cout << i << std::endl;
  }
};

int main()
{
  std::initializer_list<int> list{1, 2, 3, 4, 5};
  list.A l(list);
  A a{1, 2, 3, 4, 5};
  B b{1, 2, 3, 4, 5}; // error: no matching function for call to 'B::B(<brace-enclosed initializer list>)'
  return 0;
}