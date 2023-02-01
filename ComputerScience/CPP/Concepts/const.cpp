/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <vector>

class Base
{
public:
  Base() { std::cout << "Base::Base()" << std::endl; }
  int sum(const std::vector<int>& v)
  {
    std::cout << "Base::sum()" << std::endl;
    int sum = 0;
    for (auto i : v)
      sum += i;
    return sum;
  }

  int sum(const std::vector<int>& v) const
  {
    std::cout << "Base::sum() const" << std::endl;
    int sum = 0;
    for (auto i : v)
      sum += i;
    return sum;
  }
};

int main()
{
  {
    Base b;
    std::vector<int> v = {1, 2, 3, 4, 5};
    int temp = b.sum(v);
    std::cout << temp << std::endl; // Base::sum()
  }
  {
    const Base b;
    std::vector<int> v = {1, 2, 3, 4, 5};
    int temp = b.sum(v);
    std::cout << temp << std::endl; // Base::sum() const
  }
  return 0;
}