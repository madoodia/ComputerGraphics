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
  virtual void fun1() = 0;
  virtual void fun2() = 0;
  virtual void foo() { std::cout << "Base.foo() called" << std::endl; }
  int getX() { return x ^ 2; }
  virtual void setX(int value) { x = value; }
};

class Derived : public Base
{
  int y;

public:
  void fun1() override { std::cout << "Derived.fun1() called" << std::endl; }
  void fun2() override { std::cout << "Derived.fun2() called" << std::endl; }
  void foo() override { std::cout << "Derived.foo() called" << std::endl; }
  int getY() { return y * 2; }
  void setY(int value) { y = value; }
};

class Derived2 : public Base
{
public:
  void fun1() override { std::cout << "Derived.fun1() called" << std::endl; }
  void fun2() override { std::cout << "Derived.fun2() called" << std::endl; }
};

int main(void)
{
  Derived2 dd;
  Derived d;
  d.fun1();
  d.foo();
  d.setX(10);
  d.setY(20);
  std::cout << d.getX() << std::endl;
  std::cout << d.getY() << std::endl;

  // -------------------------------------------- //
  // Base b; // error: cannot declare variable 'b' to be of abstract type 'Base'
  Base* b1 = new Derived;
  b1->fun1();
  b1->fun2();
  b1->foo();
  b1->setX(100);
  // b1.setY(200); // can not access to derived class members
  std::cout << b1->getX() << std::endl;
  // std::cout << b1->getY() << std::endl; // can not access to derived class members

  return 0;
}