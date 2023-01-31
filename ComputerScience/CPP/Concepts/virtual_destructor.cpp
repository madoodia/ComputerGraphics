/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Base
{
public:
  Base() { std::cout << "Base Constructor" << std::endl; }
  virtual ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Derived1 : public Base
{
public:
  Derived1() { std::cout << "Derived1 Constructor" << std::endl; }
  ~Derived1() { std::cout << "Derived1 Destructor" << std::endl; }
};

class Derived2 : public Base
{
public:
  Derived2() { std::cout << "Derived2 Constructor" << std::endl; }
  ~Derived2() { std::cout << "Derived2 Destructor" << std::endl; }
};

int main()
{
  Base* d1 = new Derived1();
  Base* d2 = new Derived2();

  delete d1;
  delete d2;
}