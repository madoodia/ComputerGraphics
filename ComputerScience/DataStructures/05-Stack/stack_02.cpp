/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <stack>

int main()
{
  std::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  std::cout << "size: " << s.size() << std::endl;
  std::cout << "top: " << s.top() << std::endl;

  s.pop();
  std::cout << "size: " << s.size() << std::endl;
  std::cout << "top: " << s.top() << std::endl;

  return 0;
}