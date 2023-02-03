/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

/*
A test based on the real project in unreal engine
*/

#include <iostream>
#pragma once

class Vector2
{
private:
  float X;
  float Y;

public:
  Vector2();
  ~Vector2();

  float GetX() const;
  float GetY() const;

  void SetX(float x);
  void SetY(float y);

  void PrintVector() const;
};

Vector2::Vector2()
    : X(0), Y(0)
{
}

Vector2::~Vector2()
{
}

float Vector2::GetX() const
{
  return X;
}

float Vector2::GetY() const
{
  return Y;
}

void Vector2::SetX(float x)
{
  X = x;
}

void Vector2::SetY(float y)
{
  Y = y;
}

void Vector2::PrintVector() const
{
  std::cout << "X: " << X << " Y: " << Y << std::endl;
}
