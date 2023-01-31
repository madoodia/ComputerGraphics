/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

// Abstract Class: can not be instantiated
class Base
{
  int x;

public:
  Base(){};
  virtual void foo() = 0;
  virtual ~Base() = 0;
};

// pure virtual Destructor must be defined
Base::~Base()
{
  std::cout << "Base destructor called" << std::endl;
}

class Derived : public Base
{
  int y;

public:
  Derived(){};
  void foo() override { std::cout << "Derived.foo() called" << std::endl; }
  ~Derived() override { std::cout << "Derived destructor called" << std::endl; }
};

int main(void)
{
  Base* d = new Derived;
  d->foo();
  return 0;
}