/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <memory>

class Rectangle
{
  int length;
  int breadth;

public:
  Rectangle(int l, int b)
  {
    length = l;
    breadth = b;
  }

  int area()
  {
    return length * breadth;
  }
};

int main()
{

  std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
  std::cout << P1->area() << std::endl;

  std::unique_ptr<Rectangle> P2;
  P2 = std::move(P1);

  std::cout << P2->area() << std::endl;

  std::shared_ptr<Rectangle> P3(new Rectangle(10, 5));
  std::cout << P3->area() << std::endl;

  std::shared_ptr<Rectangle> P4;
  P4 = P3;
  std::cout << P4->area() << std::endl;

  return 0;
}