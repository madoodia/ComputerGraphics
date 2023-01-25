/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class MyString
{
public:
  MyString(const char* str = "")
  {
    m_size = strlen(str);
    m_data = new char[m_size + 1];
    strcpy(m_data, str);
  }

  ~MyString()
  {
    delete[] m_data;
  }

  // Move Constructor
  MyString(MyString&& other)
  {
    std::cout << "Move Constructor" << std::endl;
    m_data = other.m_data;
    m_size = other.m_size;
    other.m_data = nullptr;
    other.m_size = 0;
  }

  // Move Assignment
  MyString& operator=(MyString&& other)
  {
    std::cout << "Move Assignment" << std::endl;
    if (this != &other)
    {
      delete[] m_data;
      m_data = other.m_data;
      m_size = other.m_size;
      other.m_data = nullptr;
      other.m_size = 0;
    }
    return *this;
  }

  // Copy Constructor
  MyString(const MyString& other) = delete;
  // Assignment Operator
  MyString& operator=(const MyString& other) = delete;

private:
  char* m_data;
  size_t m_size;
};

int main()
{
  MyString s1("Hello");
  MyString s2 = std::move(s1); // Move Constructor
  MyString s3;
  s3 = std::move(s2); // Move Assignment

  return 0;
}