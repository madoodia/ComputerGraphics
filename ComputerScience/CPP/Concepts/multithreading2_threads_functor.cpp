/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <cstdlib>

#include <iostream>
#include <thread>
#include <vector>

class CalcFunctor
{
public:
  void operator()(const std::vector<int>& vec,
                  unsigned int beginIndex, unsigned int endIndex)
  {
    _acm = 0;
    for (unsigned int i = beginIndex; i < endIndex; ++i)
    {
      _acm += vec[i];
    }
  }
  unsigned long long _acm;
};

int main()
{
  std::vector<int> vec = {};

  for (int i = 0; i < 10; i++)
  {
    vec.push_back(rand() % 10 + 1);
  }

  // for (int i = 0; i < vec.size(); i++)
  // {
  //     std::cout << vec[i] << std::endl;
  // }

  CalcFunctor accumulator1;
  CalcFunctor accumulator2;
  std::thread t1(std::ref(accumulator1),
                 std::ref(vec), 0, vec.size() / 2);
  std::thread t2(std::ref(accumulator2),
                 std::ref(vec), vec.size() / 2, vec.size());
  t1.join();
  t2.join();

  std::cout << "acm1: " << accumulator1._acm << std::endl;
  std::cout << "acm2: " << accumulator2._acm << std::endl;
  std::cout << "accumulator1._acm + accumulator2._acm : " << accumulator1._acm + accumulator2._acm << std::endl;

  return 0;
}