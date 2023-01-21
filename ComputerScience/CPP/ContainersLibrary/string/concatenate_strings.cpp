/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <sstream>
#include <string>
#include <vector>
#include <format>
#include <sstream>

int main()
{
  // concatenate strings
  {
    std::string str1 = "hello";
    std::string str2 = "world";
    std::string str3 = str1 + " " + str2;
  }

  // method 2
  {
    std::string str1 = "hello";
    std::string str2 = "world";
    std::string str3 = std::format("{} {}", str1, str2); // c++23
  }

  // method 3
  {
    std::string str1 = "Hello";
    std::string str2 = " World";
    str1 += str2; // str1 is now "Hello World"}
  }

  // method 4
  {
    std::string str1 = "Hello";
    std::string str2 = " World";
    str1.append(str2); // str1 is now "Hello World"}
  }

  // method 5
  {
    std::string str1 = "Hello";
    std::string str2 = " World";
    str1.insert(str1.end(), str2.begin(), str2.end()); // str1 is now "Hello World"}
  }

  // method 6
  {
    std::string str1 = "Hello";
    std::string str2 = " World";
    std::stringstream ss;
    ss << str1 << str2;
    std::string str3 = ss.str(); // str3 is "Hello World"}
  }
}