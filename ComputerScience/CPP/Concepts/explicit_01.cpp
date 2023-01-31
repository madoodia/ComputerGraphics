/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class A
{

public:
  A(int x) : x(x) {}
  int x;
};

class B
{

public:
  explicit B(int x) : x(x) {}
  int x;
};

int main()
{
  // A a1;     // Error, not have default constructor
  // A a2 = 1; // OK
  // B b = 1;  // Error
  // B b(1);   // OK
  // B b2;     // Error

  A a3 = 'a';
  B b3('b');
  std::cout << a3.x << std::endl;
  std::cout << b3.x << std::endl;

  return 0;
}