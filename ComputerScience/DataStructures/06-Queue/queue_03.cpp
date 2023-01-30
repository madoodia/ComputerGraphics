/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <queue>
#include <deque>

int main()
{
  std::queue<int> q({1, 2, 3, 4, 5});
  q.push(6);
  q.push(7);

  std::cout << "q.front() = " << q.front() << std::endl;

  q.pop();
  std::cout << "q.front() = " << q.front() << std::endl;
  std::cout << "q.front() = " << q.front() << std::endl;
  std::cout << "q.back() = " << q.back() << std::endl;
  std::cout << "q.size() = " << q.size() << std::endl;
  std::cout << "q.empty() = " << q.empty() << std::endl;

  std::cout << "----------------" << std::endl;
  std::deque<int> d({1, 2, 3, 4, 5});
  d.push_back(6);
  d.push_back(7);

  std::cout << "d.front() = " << d.front() << std::endl;

  d.pop_front();

  std::cout << "d.front() = " << d.front() << std::endl;
  d.push_front(0);
  std::cout << "d.front() = " << d.front() << std::endl;
  d.pop_back();
  std::cout << "d.back() = " << d.back() << std::endl;
  std::cout << "d.size() = " << d.size() << std::endl;
  std::cout << "d.empty() = " << d.empty() << std::endl;

  std::cout << "----------------" << std::endl;

  return 0;
}