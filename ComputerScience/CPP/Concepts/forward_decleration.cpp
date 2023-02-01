/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class B;

class A : public B
{
public:
  A()
  {
    // B b; // error
  }
  ~A() {}
};

class B
{
public:
  B()
  {
    class C c;
  }
  ~B() {}
};

class C
{
public:
  C() {}
  ~C() {}
};

int main()
{
  A a;

  return 0;
}