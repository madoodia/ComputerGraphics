/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/
#include <iomanip>

#include "core.h"

/*
I is a vector
P is a vector
IP is a vector from I to P = P - I
*/

int main()
{
  {
    Point p;
    p.x = 1.0f;
    p.y = 2.0f;

    Vector v;
    v.x = 3.0f;
    v.y = 4.0f;

    Point result = p.AddVector(v);
    std::cout << result.x << ", " << result.y << std::endl;
    std::cout << "--------------" << std::endl;
  }

  {
    Point p;
    p.x = 1.0f;
    p.y = 2.0f;

    Point i;
    i.x = 3.0f;
    i.y = 4.0f;

    Vector result = p - i;
    std::cout << result.x << ", " << result.y << std::endl;
    std::cout << "Vector Length: " << result.Length() << std::endl;
    std::cout << "--------------" << std::endl;
  }
  {
    Point p;
    p.x = 0.0f;
    p.y = -1.0f;

    Point i;
    i.x = 1.0f;
    i.y = 1.0f;

    Point c;
    c.x = 2.0f;
    c.y = -1.0f;

    Vector IP = p - i;
    Vector CP = p - c;

    std::cout << "IP Length: " << IP.LengthSquared() << std::endl;
    std::cout << "CP Length: " << CP.LengthSquared() << std::endl;

    // print CP.length with double percision
    // std::cout << "CP Length (Double Percision): " << std::setprecision(10) << CP.LengthSquared() << std::endl;

    std::cout << "--------------" << std::endl;
  }
  {
    Vector vec1(3, 4, 0);

    Vector doubledVec = vec1 * 2.0f;
    Vector halfVec = vec1 / 2.0f;

    std::cout << "Doubled Vector: " << doubledVec.Length() << std::endl;
    std::cout << "Half Vector: " << halfVec.Length() << std::endl;

    std::cout << "--------------" << std::endl;
  }

  {
    Point a(2, 4, 0);
    Point b(1, -1, 0);

    Vector ba = a - b;
    std::cout << "Vector ba: " << ba.x << ", " << ba.y << std::endl;
    std::cout << "Distance from a to b: " << ba.Length() << std::endl;

    Vector Normalized = ba.Normalized();
    std::cout << "Unit Vector: " << Normalized.x << ", " << Normalized.y << std::endl;

    Vector c(1, 1, 0);
    float distance = ba.Distance(c);
    std::cout << "Distance from c to ba: " << distance << std::endl;

    std::cout << "--------------" << std::endl;
  }

  {
    Vector u(5, 0, 0);
    Vector v(0, -3, 0);

    Vector z = u + v;
    std::cout << "Z (Velocity): " << z.x << ", " << z.y << std::endl;
    std::cout << "--------------" << std::endl;
  }

  // Mid Point
  {
    Point a = {-5, -2, 0};
    Point b = {-1, 2, 0};

    Vector displacement = a - b;
    std::cout << "Displacement: " << displacement.x << ", " << displacement.y << std::endl;
    std::cout << "Displacement Length: " << displacement.Length() << std::endl;
    Vector midPoint = MidPoint(a, b);
    std::cout << "Mid Point: {" << midPoint.x << ", " << midPoint.y << "}" << std::endl;
    std::cout << "MidPoint Length: " << midPoint.Length() << std::endl;
    std::cout << "--------------" << std::endl;
  }

  // Get Forward Vector
  {
    float Rotation = 0.0f;

    Vector Forward = GetForward(Rotation);
    std::cout << "Forward: " << Forward.x << ", " << Forward.y << std::endl;
    std::cout << "--------------" << std::endl;
  }

  // Dot Product
  {
    Vector a(3, 0, 0);
    Vector b(-3, 1, 0);

    float dot = Dot(a.Normalized(), b.Normalized());
    std::cout << "Dot: " << dot << std::endl;
    std::cout << "--------------" << std::endl;
  }

  // Game Loop and Delta Time
  {
    Entity Mario;
    Mario.Position = Point(0, 0, 0);
    Mario.Angle = 0.0f;
    Mario.Velocity = Vector(2, 2, 0);
    Mario.Gravity = Vector(0, -2.0f, 0);

    float PrevTime = 0.0f;
    float CurrentTime = GetCurrentTime();

    int c = 0;

    while (c < 1000)
    {

      PrevTime = CurrentTime;
      CurrentTime = GetCurrentTime();

      float dt = CurrentTime - PrevTime;

      if (dt > 0.015f)
        dt = 0.015f;

      Update(Mario, dt);
      if (c % 1000 == 0)
        Render(Mario);
      c++;
    }
  }

  // Cross Product
  {
    Vector a(1, 0, 0);
    Vector b(0, 1, 0);

    Vector cross = Cross(a, b);
    std::cout << "Cross: " << cross.x << ", " << cross.y << cross.z << std::endl;
    std::cout << "--------------" << std::endl;
  }
}