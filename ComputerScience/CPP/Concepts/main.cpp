/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

/*
A test based on the real project in unreal engine
*/

#include <iostream>
#include "vector2.h"

class Level
{
public:
  Level();
  ~Level();

  Vector2* OurVector; // equivalent to Variable object reference in unreal engine blueprints
};

Level::Level()
{
  OurVector = new Vector2(); // equivalent to Construct an object from a class in unreal engine blueprints

  float temp = 0;

  OurVector->SetX(10);
  OurVector->SetY(20);

  temp = OurVector->GetX() * 5 + OurVector->GetY();

  OurVector->SetY(temp);

  OurVector->PrintVector();
}

Level::~Level()
{
}

// ----------------------------
int main()
{
  Level level;

  return 0;
}