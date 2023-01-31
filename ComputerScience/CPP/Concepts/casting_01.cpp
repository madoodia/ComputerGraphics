/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Base
{
public:
  virtual void foo()
  {
    std::cout << "Base::foo()" << std::endl;
  }

private:
  virtual void bar()
  {
    std::cout << "Base::bar()" << std::endl;
  }
};

class Derived : public Base
{
public:
  void foo() override
  {
    std::cout << "Derived::foo()" << std::endl;
  }

private:
  void bar() override
  {
    std::cout << "Derived::bar()" << std::endl;
  }
};

int main()
{
  Base* base = new Base();
  Derived* derived = new Derived();

  // Upcast
  Base* base2 = derived;
  // Downcast
  Derived* derived2 = (Derived*)base;

  Base* base3 = new Derived;
  Derived* derived3 = dynamic_cast<Derived*>(base3); // If you don't have at least one virtual function in the base class, this will fail

  base->foo();
  derived->foo();
  base2->foo();
  derived2->foo();
  base3->foo();
  derived3->foo();

  base->bar();
  derived->bar();
  base2->bar();
  derived2->bar();
  base3->bar();
  derived3->bar();

  return 0;
}