/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Shape
{
public:
  Shape()
  {
    std::cout << "Shape::Shape()" << std::endl;
  }
  virtual void draw()
  {
    std::cout << "Shape::draw()" << std::endl;
  }

  virtual ~Shape()
  {
    std::cout << "Shape::~Shape()" << std::endl;
  }
};

class Circle : public Shape
{
public:
  Circle()
  {
    std::cout << "Circle::Circle()" << std::endl;
  }

  virtual void draw() override
  {
    std::cout << "Circle::draw()" << std::endl;
  }

  ~Circle()
  {
    std::cout << "Circle::~Circle()" << std::endl;
  }
};

class Rectangle : public Shape
{
public:
  Rectangle()
  {
    std::cout << "Rectangle::Rectangle()" << std::endl;
  }
  virtual void draw() final override // last implementation
  {
    std::cout << "Rectangle::draw()" << std::endl;
  }

  ~Rectangle()
  {
    std::cout << "Rectangle::~Rectangle()" << std::endl;
  }
};

class Square : public Rectangle
{
public:
  Square()
  {
    std::cout << "Square::Square()" << std::endl;
  }

  ~Square()
  {
    std::cout << "Square::~Square()" << std::endl;
  }

  // void draw() // error
  // {
  //   std::cout << "Square::draw()" << std::endl;
  // }
};

int main()
{
  Shape* s = new Circle();
  s->draw();
  delete s;

  s = new Rectangle();
  s->draw();
  delete s;

  return 0;
}
