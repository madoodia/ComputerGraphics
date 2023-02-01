/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <vector>

class Date
{
public:
  Date() {}
  Date(int day, int month, int year) : day(day), month(month), year(year) {}

  // static int temp = 10; // error: ISO C++ forbids in-class initialization of non-const static member ‘Date::temp’
  const static int temp2 = 10;
  static int temp3;

  static void staticFunc();
  void printMe() const;

private:
  int m_a;
  int day;
  int month;
  int year;
};

int Date::temp3 = 10;

void Date::printMe() const
{
  std::cout << "temp2: " << temp2 << std::endl;
  std::cout << "temp3: " << temp3 << std::endl;
  std::cout << "year: " << year << std::endl;
}

void Date::staticFunc()
{
  std::cout << "temp2: " << temp2 << std::endl;
  std::cout << "temp3: " << temp3 << std::endl;
  // std::cout << "year: " << year << std::endl; // error: ‘int Date::year’ is private within this context
}

int main()
{

  // std::vector<Date> dates(100); // error: no matching function for call to ‘Date::Date()’
  std::vector<Date> dates2(100, Date(1));

  return 0;
}