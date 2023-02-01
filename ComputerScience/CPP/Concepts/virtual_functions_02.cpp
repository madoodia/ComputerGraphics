/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Round
{
public:
  Round()
  {
    std::cout << "Round::Round()" << std::endl;
  }

  virtual ~Round()
  {
    std::cout << "Round::~Round()" << std::endl;
  }
  virtual void whatAreYou()
  {
    std::cout << "Round::whatAreYou()" << std::endl;
  }
};

class Walnut : public Round
{
public:
  Walnut()
  {
    std::cout << "Walnut::Walnut()" << std::endl;
  }

  virtual ~Walnut()
  {
    std::cout << "Walnut::~Walnut()" << std::endl;
  }
  void whatAreYou()
  {
    std::cout << "Walnut::whatAreYou()" << std::endl;
  }
};

int main()
{
  Round* rp = new Walnut;

  rp->whatAreYou(); // if the method is not virtual, it will call the base class method

  return 0;
}