/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  char str[12] = "Hello World";
  std::cout << str << std::endl;
  std::cout << str[0] << std::endl;
  str[0] = 'A';
  std::cout << str[0] << std::endl;
  std::cout << str << std::endl;

  char* str2 = new char[12];
  str2[0] = 'B';
  str2[1] = 'C';
  str2[2] = 'D';
  str2[3] = '\0';
  std::cout << str2 << std::endl;
  // str2 = "Hello World"; // This is not allowed

  const char* str3 = "Hello World";
  std::cout << str3 << std::endl;

  std::string str4 = "Hello World";
  // or
  std::string str5 = str;
  // or
  std::string str6(str);
  // or
  std::string str7(str, 5);
  // or
  std::string str8(str, 5, 3);
  // or
  std::string str9(5, 'A');
  // or
  std::string str10(str3);
  std::cout << "str4: " << str4 << std::endl;
  std::cout << "str5: " << str5 << std::endl;
  std::cout << "str6: " << str6 << std::endl;
  std::cout << "str7: " << str7 << std::endl;
  std::cout << "str8: " << str8 << std::endl;
  std::cout << "str9: " << str9 << std::endl;
  std::cout << "str10: " << str10 << std::endl;

  str4 = "goodbye!";

  const char* nonModifiableStr = str4.c_str();
  std::cout << nonModifiableStr << std::endl;
  nonModifiableStr = "Hello World";
  // nonModifiableStr[0] = 'A'; // This is not allowed
  std::cout << nonModifiableStr << std::endl;

  std::cout << "str4.find(): " << str4.find("bye") << std::endl;
  str4.erase(5, 2);
  std::cout << "str4 " << str4 << std::endl;

  std::string str11 = "Hello my name is madoodia";
  std::cout << "str11 capacity: " << str11.capacity() << std::endl;
  std::cout << "str11 size: " << str11.size() << std::endl;

  // iterator
  std::string::iterator it = str11.begin();
  std::cout << "str11 begin: " << *it << std::endl;
  // it = str11.end();
  // std::cout << "str11 end: " << *it << std::endl;
  for (std::string::iterator it2 = str11.begin(); it2 != str11.end(); it2++)
  {
    std::cout << *it2;
  }

  for (std::string::iterator it2 = str11.begin(); it2 != str11.end(); it2++)
  {
    *it2 = 'A';
    std::cout << *it2;
  }

  for (std::string::const_iterator it2 = str11.cbegin(); it2 != str11.cend(); it2++)
  {
    // *it2 = 'A'; // This is not allowed
    std::cout << *it2;
  }
  // or
  for (auto it3 = str11.begin(); it3 != str11.end(); it3++)
  {
    std::cout << *it3;
  }
  // or
  for (auto it4 : str11)
  {
    std::cout << it4;
  }
  std::cout << std::endl;
  std::cout << "-----------" << std::endl;

  std::cout << str10 << std::endl;
  std::reverse(str10.begin(), str10.end());
  std::cout << str10 << std::endl;
  str10.reserve();
  std::cout << str10 << std::endl;

  return 0;
}