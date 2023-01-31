/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
class Base
{
public:
  int x = 0, y = 0;
};

class Derived : public Base
{
public:
  int z = 0, w = 0;
};

int main()
{
  Derived d;

  // Object Slicing,
  // z and w of d are sliced off
  Base b = d;
  d.x = 1;
  b.x = 1;
  // b.z = 1; // Error, Slice off
}