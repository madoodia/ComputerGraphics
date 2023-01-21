/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>
#include <string>

int main()
{
  std::string myString = "Hello World!";
  std::cout << myString << std::endl;
  std::cout << myString.size() << std::endl;

  // assign a new value to the first element of the string
  myString.at(0) = 'G';
  std::cout << myString << std::endl;

  // assign a new value to the last element of the string
  myString.at(myString.size() - 1) = '?';
  std::cout << myString << std::endl;

  std::string myString2 = "Hello World!";
  // or
  std::string myString3 = myString; // assignment operator
  // or
  std::string myString4(myString); // copy constructor
  // or
  std::string myString5 = std::string(myString);
  // or
  std::string myString6 = std::string("Hello World!");

  // create a constexptr string
  constexpr std::string_view myString7 = "Hello World!";
  // myString7.at(0) = 'G'; // error: cannot assign to variable 'myString7' with const-qualified type 'const std::string_view'
  myString5[2] = myString7[0]; // ok

  // create a string pointer
  std::string* myString8 = new std::string("Hello World!");
  std::cout << *myString8 << std::endl;
  delete myString8;
}