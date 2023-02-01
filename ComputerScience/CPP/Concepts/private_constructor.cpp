/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Base
{

public:
  static Base& callMe()
  {
    Base b;
    return b;
  }

private:
  Base() {} // private constructor
};

int main()
{
  // Base b; // error: ‘Base::Base()’ is private within this context
  Base b = Base::callMe();

  return 0;
}