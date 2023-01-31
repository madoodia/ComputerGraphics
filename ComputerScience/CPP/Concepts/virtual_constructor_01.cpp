/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

/*
In practical scenarios, we would need to create a derived class object in a class hierarchy based on some input.
In other words, object creation and object type are tightly coupled which forces modifications to extended.
The objective of the virtual constructor is to decouple object creation from its type.
*/

#include <iostream>

class Test
{
public:
  virtual Test(){}; // virtual constructor is not allowed
};

int main()
{
  return 0;
}