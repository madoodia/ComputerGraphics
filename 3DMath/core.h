/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/
#include <iostream>
#include <chrono>

// Vector Class --------------------------------------------------------
class Vector
{
public:
  float x, y, z;

  Vector() : x(0.0f), y(0.0f), z(0.0f) {}
  Vector(float x, float y, float z) : x(x), y(y), z(z) {}

  Vector operator-(const Vector& other) const;
  Vector operator+(const Vector& other) const;
  Vector operator*(float scalar) const;
  Vector operator/(float scalar) const;

  float Length() const;
  float LengthSquared() const;
  Vector Normalized() const;
  float Distance(const Vector& other) const;
};

Vector Vector::operator-(const Vector& other) const
{
  return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator+(const Vector& other) const
{
  return Vector(x + other.x, y + other.y, z + other.z);
}
Vector Vector::operator*(float scalar) const
{
  return Vector(x * scalar, y * scalar, z * scalar);
}

Vector Vector::operator/(float scalar) const
{
  return Vector(x / scalar, y / scalar, z / scalar);
}

float Vector::Length() const
{
  return sqrt(x * x + y * y + z * z);
}

float Vector::LengthSquared() const
{
  return x * x + y * y + z * z;
}

Vector Vector::Normalized() const
{
  float length = Length();
  return (*this) / length;
}

float Vector::Distance(const Vector& other) const
{
  float dx = x - other.x;
  float dy = y - other.y;
  float dz = z - other.z;
  return sqrt(dx * dx + dy * dy + dz * dz);
}

float Dot(const Vector& a, const Vector& b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector Cross(const Vector& a, const Vector& b)
{
  return Vector(a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x);
}

Vector GetForward(float angle)
{
  return Vector(std::cos(angle), std::sin(angle), 0.0f).Normalized();
}

// ======================================================================
// Point Class --------------------------------------------------------
class Point
{
public:
  float x, y, z;

  Point() : x(0.0f), y(0.0f), z(0.0f) {}
  Point(float x, float y, float z) : x(x), y(y), z(z) {}

  Point AddVector(Vector v);
  Vector operator-(Point p1) const;
  Point operator+(Vector v1) const;
  Point operator=(Vector v1) const;
};

Point Point::AddVector(Vector v)
{
  Point result;
  result.x = x + v.x;
  result.y = y + v.y;
  result.z = z + v.z;
  return result;
}

Vector Point::operator-(Point p1) const
{
  Vector result;
  result.x = this->x - p1.x;
  result.y = this->y - p1.y;
  result.z = this->z - p1.z;
  return result;
}

Point Point::operator+(Vector v1) const
{
  Point result;
  result.x = this->x + v1.x;
  result.y = this->y + v1.y;
  result.z = this->z + v1.z;
  return result;
}

Vector MidPoint(Point p1, Point p2)
{
  Vector result;
  result.x = (p1.x + p2.x) / 2.0f;
  result.y = (p1.y + p2.y) / 2.0f;
  result.z = (p1.z + p2.z) / 2.0f;
  return result;
}

// ======================================================================
// Entity Class --------------------------------------------------------

class Entity
{
public:
  Point Position;
  Vector Velocity;
  Vector Gravity;
  float Angle;
  float Speed;
};

void Update(Entity& e, float dt)
{
  e.Position = e.Position + e.Velocity * dt;
  e.Velocity = e.Velocity + e.Gravity * dt;
}

void Render(Entity& e)
{
  std::cout << "Position: " << e.Position.x << ", " << e.Position.y << std::endl;
  std::cout << "Velocity: " << e.Velocity.x << ", " << e.Velocity.y << std::endl;
}

float GetCurrentTime()
{
  std::chrono::steady_clock::time_point time;
  time = std::chrono::steady_clock::now();

  auto time_since_epoch = time.time_since_epoch();
  auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(time_since_epoch).count();
  auto result = (float)milliseconds;
  return result;
}

float Approach(float current, float target, float dt)
{
  float diff = target - current;
  if (diff > dt)
    return current + dt;
  if (diff < -dt)
    return current - dt;

  return target;
}

// ======================================================================
// Euler Class --------------------------------------------------------

class EAngle
{
public:
  EAngle() : p(0.0f), y(0.0f), r(0.0f) {}
  EAngle(float pitch, float yaw, float roll) : p(pitch), y(yaw), r(roll) {}

  Vector ToVector() const;
  void Normalized();

public:
  float p;
  float y;
  float r;
};

Vector EAngle::ToVector() const
{
  return Vector(std::cos(y) * std::cos(p),
                std::sin(p),
                std::sin(y) * std::cos(p));
}

void EAngle::Normalized()
{
  if (p > 89.0f)
    p = 89.0f;
  if (p < -89.0f)
    p = -89.0f;

  while (y < -180.0f)
    y += 360.0f;
  while (y > 180.0f)
    y -= 360.0f;
}